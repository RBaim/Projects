//
// Created by radmi on 06.09.2017.
//
#include "AneuMeshLoader.h"

void AneuMeshLoader::LoadMesh(const std::string& name_file) {
    std::string::size_type n;
    n = name_file.find(".aneu");
    if(n == std::string::npos) throw Exc(1, "files error format");
    std::ifstream fout(name_file);
    if(!fout.is_open()) throw Exc(2, "files not found");
    int count, dim, i = 1;
    fout >> count >> dim;
    s_node.resize(count);
    forEach(s_node.begin(), s_node.end(), [&dim, &fout, &i](Node& elem){elem.coords.resize(dim); elem.ID = i++;
        forEach(elem.coords.begin(), elem.coords.end(),[&fout](double& el){fout >> el;});});
    fout >> count >> dim;
    s_elem.resize(count);
    forEach(s_elem.begin(), s_elem.end(), [&fout, &dim](Element& ke) {fout >> ke.material_ID;
        ke.ID_node.resize(dim); forEach(ke.ID_node.begin(), ke.ID_node.end(),[&fout](int& el){fout >> el;});});
    fout >> count >> dim;
    s_surf.resize(count);
    forEach(s_surf.begin(), s_surf.end(), [&fout, &dim](Surface& sr){fout >> sr.ID_surf_cond; sr.ID_node.resize(dim);
    forEach(sr.ID_node.begin(), sr.ID_node.end(), [&fout](int& el){fout >> el;});});
}
