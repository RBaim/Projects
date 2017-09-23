//
// Created by radmi on 06.09.2017.
//
#include "MeshLoader.h"

void MeshLoader::OutData() {
    int i = 1;
    std::cout << "Nodes:" << std::endl;
    std::for_each(s_node.begin(), s_node.end(), [&i](Node el){std::cout << std::setw(4) << el.ID << ": ";
        std::cout << std::setw(9) << std::fixed << std::setprecision(4) << el.x << std::setw(9) << std::fixed << el.y
                  << std::setw(9) << std::fixed <<el.z << std::endl; el.apex = true;});
    std::cout << "Elements:" << std::endl;
    std::for_each(s_elem.begin(), s_elem.end(), [&i](Element el){std::cout << std::setw(4) << i++ << ": " << std::setw(4) << el.material_ID << ' ';
        std::for_each(el.ID_node.begin(), el.ID_node.end(),[](int& i){std::cout << std::setw(9) << i++ << ' ';}); std::cout << std::endl;});
    std::cout << "Surfaces:" << std::endl;
    i = 1;
    std::for_each(s_surf.begin(), s_surf.end(), [&i](Surface sr){std::cout << std::setw(4) << i++ << ": " << std::setw(4) << sr.ID_surf_cond << ' ';
        std::for_each(sr.ID_node.begin(), sr.ID_node.end(), [](int& i){std::cout<< std::setw(9) << i++ << ' ';}); std::cout << std::endl;});
}

std::vector<Node> MeshLoader::GetNode() {
    return s_node;
}

std::vector<Element> MeshLoader::GetElement() {
    return s_elem;
}

std::vector<Surface> MeshLoader::GetSurface() {
    return s_surf;
}

class Predicate {
    int* ID;
    int size;
    bool NextSet(int *a, int n, int m) {
        int j;
        do {
            j = n - 1;
            while (j != -1 && a[j] >= a[j + 1]) j--;
            if (j == -1)
                return false;
            int k = n - 1;
            while (a[j] >= a[k]) k--;
            std::swap(a[j], a[k]);
            int l = j + 1, r = n - 1;
            while (l < r)
                std::swap(a[l++], a[r--]);
        } while (j > m - 1);
        return true;
    }
    bool Find(int *a, int n, Element* el) {
        for (int i = 0; i < n; i++)
            if(ID[i] != (*el).ID_node[a[i]]) return false;
        return true;
    }
public:
    Predicate(int* ID_p, int size_p){
        ID = ID_p;
        size = size_p;
    }
    bool operator()(Element& el_p) {
        int *a;
        int n = el_p.ID_node.size();
        int m = size;
        a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = i;
        if(Find(a, m, &el_p)) return true;
        while (NextSet(a, n, m))
            if(Find(a, m, &el_p)) return true;
        return false;
    }
};

std::vector<Element> MeshLoader::FindElements(int *ID, int size) {
    std::vector<Element> find_el;
    auto el = s_elem.begin();
    do {
        el = std::find_if(el, s_elem.end(), Predicate(ID, size));
        if(s_elem.end() != el) {find_el.push_back(*el); ++el;}
        else break;
    } while(1);
    return  find_el;
}

std::vector<Element> MeshLoader::FindElemIDmater(int ID_material) {
    std::vector<Element> find_el;
    std::copy_if(s_elem.begin(), s_elem.end(), find_el.begin(), [&ID_material](Element& el){if(ID_material == el.material_ID) return true; return false;});
    return find_el;
}

std::vector<Surface> MeshLoader::FindSurfIDcond(int IDcond) {
    std::vector<Surface> find_sr;
    std::copy_if(s_surf.begin(), s_surf.end(), find_sr.begin(), [&IDcond](Surface& sr){if(IDcond == sr.ID_surf_cond) return true; return false;});
    return find_sr;
}

std::vector<int> MeshLoader::FindNodeIDcond(int IDcond) {
    std::vector<int> find_nd;
    std::for_each(s_surf.begin(), s_surf.end(), [&](Surface& sr){if(sr.ID_surf_cond == IDcond)
        for(int i = 0; i < sr.ID_node.size(); ++i) {
            bool key = true;
            for(int j = 0; j < find_nd.size(); ++j)
                if(find_nd[j] == sr.ID_node[i]) key = false;
            if(key) find_nd.push_back(s_node[sr.ID_node[i] - 1].ID);}});
    return find_nd;
}

std::vector<std::vector<int>> MeshLoader::NeighborElementEach() {
    std::vector<std::vector<int>> res;
    bool sear;
    bool key;
    std::vector<int> tmp;
    std::for_each(s_node.begin(), s_node.end(), [&](Node& nd) {
        std::for_each(s_elem.begin(), s_elem.end(), [&](Element& el) {
            key = false;
            for(int i = 0; i < el.ID_node.size(); ++i)
                if(el.ID_node[i] == nd.ID) {key = true; break;}
            if(key) {
                for(int i = 0; i < el.ID_node.size(); ++i) {
                    sear = true;
                    if(el.ID_node[i] != nd.ID) {
                        for (int j = 0; j < tmp.size(); ++j)
                            if (tmp[j] == el.ID_node[i]) sear = false;
                    } else {
                        sear = false;
                    }
                    if(sear) tmp.push_back(s_node[el.ID_node[i] - 1].ID);
                }
            }
        });
        res.push_back(tmp);
        tmp.clear();});
    return res;
}

std::vector<std::vector<int>> SearchRebr(int n) {
    std::vector<std::vector<int>> res;
    std::vector<int> tmp;
    int sumb = 0;
    int k = 0;
    for (int i = 1; i < pow(2, n); i++) {
        for (int j = 0; j < n; j++)
            if (((1<<j)&i)!= 0)
                sumb++;
        if (sumb == 2) {
            k = i;
            int s = 0;
            while (k) {
                if(k % 2) tmp.push_back(s);
                k /= 2;
                s++;
            }
            res.push_back(tmp);
            tmp.clear();
        }
        sumb = 0;
    }
    return res;
}


void MeshLoader::Modify() {
    std::vector<std::vector<int>> gen(SearchRebr(4));
    for(int i = 0; i < gen.size(); ++i)
        std::cout << gen[i][0] << ' ' << gen[i][1] << std::endl;
    std::vector<std::pair<bool, std::vector<int>>> ch;
    int count = s_node.size() + 1;
    std::for_each(s_elem.begin(), s_elem.end(), [&](Element& el){
        for(int i = 0; i < gen.size(); ++i) {
            if(ch.end() == std::find_if(ch.begin(), ch.end(), [&](std::pair<bool, std::vector<int>> p){
                if((p.second[0] == el.ID_node[gen[i][0]] && p.second[1] == el.ID_node[gen[i][1]])
                   || (p.second[0] == el.ID_node[gen[i][1]] && p.second[1] == el.ID_node[gen[i][0]]))
                    return true;
                return false;
            }))
                ch.push_back(std::make_pair(false, std::vector<int>({el.ID_node[gen[i][0]], el.ID_node[gen[i][1]], count++})));
        }
    });
    std::for_each(s_elem.begin(), s_elem.end(), [&](Element& el) {
        Node n_n;
        for(int i = 0; i < gen.size(); ++i) {
            auto p_el = std::find_if(ch.begin(), ch.end(), [&](std::pair<bool, std::vector<int>> p) {
                if((p.second[0] == el.ID_node[gen[i][0]] && p.second[1] == el.ID_node[gen[i][1]])
                        || (p.second[0] == el.ID_node[gen[i][1]] && p.second[1] == el.ID_node[gen[i][0]]))
                    return true;
                return false;
            });
            el.ID_node.push_back((*p_el).second[2]);
            if(!(*p_el).first) {
                (*p_el).first = true;
                n_n.apex = false;
                n_n.ID = (*p_el).second[2];
                n_n.x = (s_node[el.ID_node[gen[i][0]] - 1].x + s_node[el.ID_node[gen[i][1]] - 1].x) / 2.0;
                n_n.y = (s_node[el.ID_node[gen[i][0]] - 1].y + s_node[el.ID_node[gen[i][1]] - 1].y) / 2.0;
                n_n.z = (s_node[el.ID_node[gen[i][0]] - 1].z + s_node[el.ID_node[gen[i][1]] - 1].z) / 2.0;
                s_node.push_back(n_n);
            }
            
        }
    });
    gen.clear();
    gen = SearchRebr(3);
    std::for_each(s_surf.begin(), s_surf.end(), [&](Surface& el) {
        for(int i = 0; i < gen.size(); ++i) {
            auto p_el = std::find_if(ch.begin(), ch.end(), [&](std::pair<bool, std::vector<int>> p) {
                if((p.second[0] == el.ID_node[gen[i][0]] && p.second[1] == el.ID_node[gen[i][1]])
                   || (p.second[0] == el.ID_node[gen[i][1]] && p.second[1] == el.ID_node[gen[i][0]]))
                    return true;
                return false;
            });
            el.ID_node.push_back((*p_el).second[2]);
        }
    });
}
