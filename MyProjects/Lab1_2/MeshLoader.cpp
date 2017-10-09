//
// Created by radmi on 06.09.2017.
//
#include "MeshLoader.h"

void MeshLoader::OutData(int node, int elem, int surf) {
    int i = 1;
    std::cout << "Nodes:" << std::endl;
    for(Node& el : s_node) {
        if(i++ == node + 1) break;
        std::cout << std::setw(4) << el.ID << ": ";
        std::cout << std::setw(9) << std::fixed << std::setprecision(4) << el.x << std::setw(9) << std::fixed << el.y
                  << std::setw(9) << std::fixed << el.z << std::endl;
    }
    i = 1;
    std::cout << "Elements:" << std::endl;
    for(Element& el : s_elem) {
        if(i++ == elem + 1) break;
        std::cout << std::setw(4) << i++ << ": " << std::setw(4) << el.material_ID << ' ';
        for(int &id : el.ID_node)
            std::cout << std::setw(9) << id << ' ';
        std::cout << std::endl;
    }
    std::cout << "Surfaces:" << std::endl;
    i = 1;
    for(Surface& sr : s_surf) {
        if(i++ == surf + 1) break;
        std::cout << std::setw(4) << i++ << ": " << std::setw(4) << sr.ID_surf_cond << ' ';
        for(int &id : sr.ID_node)
            std::cout << std::setw(9) << id << ' ';
        std::cout << std::endl;
    }
}

void MeshLoader::OutData(std::ostream_iterator<double> iter) {
    *iter = s_node.size();
    for(Node& el : s_node) {
        *iter = el.x;
        *iter = el.y;
        *iter = el.z;
    }
    *iter = s_elem.size();
    for(Element& el : s_elem) {
        *iter = el.material_ID;
        for(int &id : el.ID_node)
            *iter = id;
    }
    *iter = s_surf.size();
    for(Surface& sr : s_surf) {
        *iter = sr.ID_surf_cond;
        for(int &id : sr.ID_node)
            *iter = id;
    }
}

std::vector<Node> &MeshLoader::GetNode() {
    return s_node;
}

std::vector<Element> &MeshLoader::GetElement() {
    return s_elem;
}

std::vector<Surface> &MeshLoader::GetSurface() {
    return s_surf;
}

class Predicate {
    int *ID;
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
    
    bool Find(int *a, int n, Element *el) {
        for (int i = 0; i < n; i++)
            if (ID[i] != (*el).ID_node[a[i]]) return false;
        return true;
    }

public:
    Predicate(int *ID_p, int size_p) {
        ID = ID_p;
        size = size_p;
    }
    
    bool operator()(Element &el_p) {
        int *a;
        int n = el_p.ID_node.size();
        int m = size;
        a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = i;
        if (Find(a, m, &el_p)) return true;
        while (NextSet(a, n, m))
            if (Find(a, m, &el_p)) return true;
        return false;
    }
};

std::vector<Element> MeshLoader::FindElements(int *ID, int size) {
    std::vector<Element> find_el;
    auto el = s_elem.begin();
    while (s_elem.end() != (el = std::find_if(el, s_elem.end(), Predicate(ID, size)))) {
        find_el.push_back(*el);
        ++el;
    }
    return find_el;
}

std::vector<Element> MeshLoader::FindElemIDmater(int ID_material) {
    std::vector<Element> find_el;
    std::copy_if(s_elem.begin(), s_elem.end(), find_el.begin(),
                 [&ID_material](Element &el) { return ID_material == el.material_ID ? true : false; });
    return find_el;
}

std::vector<Surface> MeshLoader::FindSurfIDcond(int IDcond) {
    std::vector<Surface> find_sr;
    std::copy_if(s_surf.begin(), s_surf.end(), find_sr.begin(),
                 [&IDcond](Surface &sr) { return IDcond == sr.ID_surf_cond ? true : false; });
    return find_sr;
}

std::vector<int> MeshLoader::FindNodeIDcond(int IDcond) {
    std::vector<int> find_nd;
    for (Surface &sr : s_surf) {
        if (sr.ID_surf_cond == IDcond) {
            for (int i = 0; i < sr.ID_node.size(); ++i) {
                bool key = true;
                for (int j = 0; j < find_nd.size(); ++j)
                    if (find_nd[j] == sr.ID_node[i]) key = false;
                if (key) find_nd.push_back(s_node[sr.ID_node[i] - 1].ID);
            }
        }
    }
    return find_nd;
}

std::vector<std::vector<int>> MeshLoader::NeighborElementEach() {
    std::vector<std::vector<int>> res;
    bool sear;
    bool key;
    std::vector<int> tmp;
    for (Node &nd : s_node) {
        for (Element &el : s_elem) {
            key = false;
            for (int i = 0; i < el.ID_node.size(); ++i)
                if (el.ID_node[i] == nd.ID) {
                    key = true;
                    break;
                }
            if (key) {
                for (int i = 0; i < el.ID_node.size(); ++i) {
                    sear = true;
                    if (el.ID_node[i] != nd.ID) {
                        for (int j = 0; j < tmp.size(); ++j)
                            if (tmp[j] == el.ID_node[i]) sear = false;
                    } else {
                        sear = false;
                    }
                    if (sear) tmp.push_back(s_node[el.ID_node[i] - 1].ID);
                }
            }
        }
        res.push_back(tmp);
        tmp.clear();
    }
    return res;
}

std::vector<std::vector<int>> SearchRebr(int n) {
    std::vector<std::vector<int>> res;
    std::vector<int> tmp;
    int sumb = 0;
    int k = 0;
    for (int i = 1; i < pow(2, n); i++) {
        for (int j = 0; j < n; j++)
            if (((1 << j) & i) != 0)
                sumb++;
        if (sumb == 2) {
            k = i;
            int s = 0;
            while (k) {
                if (k % 2) tmp.push_back(s);
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

class find_pred {
    std::vector<std::vector<int>> gen;
    Element el;
    int i;
public:
    find_pred(const std::vector<std::vector<int>>&& p_gen, const Element&& p_el, const int&& p_i) : gen(p_gen), el(p_el), i(p_i) { }
    bool operator() (std::pair<bool, std::vector<int>>& p) {
        return ((p.second[0] == el.ID_node[gen[i][0]] && p.second[1] == el.ID_node[gen[i][1]])
                || (p.second[0] == el.ID_node[gen[i][1]] && p.second[1] == el.ID_node[gen[i][0]])) ?
               true : false;
    }
};

void MeshLoader::Modify() {
    std::vector<std::vector<int>> gen(SearchRebr(4));
    /*for (int i = 0; i < gen.size(); ++i)
        std::cout << gen[i][0] << ' ' << gen[i][1] << std::endl;*/
    std::vector<std::pair<bool, std::vector<int>>> ch;
    int count = s_node.size() + 1;
    for (Element &el : s_elem) {
        for (int i = 0; i < gen.size(); ++i) {
            if (ch.end() == std::find_if(ch.begin(), ch.end(), find_pred(std::move(gen), std::move(el), std::move(i))))
                ch.push_back(std::move(std::make_pair(false,
                                            std::move(std::vector<int>
                                                    ({el.ID_node[gen[i][0]],
                                                      el.ID_node[gen[i][1]], count++})))));
        }
    }
    for (Element &el : s_elem) {
        Node n_n;
        for (int i = 0; i < gen.size(); ++i) {
            auto p_el = std::find_if(ch.begin(), ch.end(), find_pred(std::move(gen), std::move(el), std::move(i)));
            el.ID_node.push_back(std::move((*p_el).second[2]));
            if (!(*p_el).first) {
                (*p_el).first = true;
                n_n.apex = false;
                n_n.ID = (*p_el).second[2];
                n_n.x = (s_node[el.ID_node[gen[i][0]] - 1].x + s_node[el.ID_node[gen[i][1]] - 1].x) / 2.0;
                n_n.y = (s_node[el.ID_node[gen[i][0]] - 1].y + s_node[el.ID_node[gen[i][1]] - 1].y) / 2.0;
                n_n.z = (s_node[el.ID_node[gen[i][0]] - 1].z + s_node[el.ID_node[gen[i][1]] - 1].z) / 2.0;
                s_node.push_back(std::move(n_n));
            }
            
        }
    }
    gen.clear();
    gen = SearchRebr(3);
    for (Surface &el : s_surf) {
        for (int i = 0; i < gen.size(); ++i) {
            auto p_el = std::find_if(ch.begin(), ch.end(), find_pred(std::move(gen), std::move(el), std::move(i)));
            el.ID_node.push_back(std::move((*p_el).second[2]));
        }
    }
}
