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
    for(int i = 0; i < count; ++i) {
        Node el;
        el.ID = i + 1;
        fout >> el.x >> el.y >> el.z;
        el.apex = true;
        s_node.push_back(el);
    }
    fout >> count >> dim;
    for(int i = 0; i < count; ++i) {
        Element ke;
        fout >> ke.material_ID;
        for(int j = 0; j < dim; ++j) {
            int el;
            fout >> el;
            ke.ID_node.push_back(std::move(el));
        }
        s_elem.push_back(std::move(ke));
    }
    fout >> count >> dim;
    for(int i = 0; i < count; ++i) {
        Surface sr;
        fout >> sr.ID_surf_cond;
        for(int j = 0; j < dim; ++j) {
            int el;
            fout >> el;
            sr.ID_node.push_back(std::move(el));
        }
        s_surf.push_back(std::move(sr));
    }
}
