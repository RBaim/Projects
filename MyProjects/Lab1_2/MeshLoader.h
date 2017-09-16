//
// Created by radmi on 06.09.2017.
//

#ifndef LAB1_2_MESHLOADER_H
#define LAB1_2_MESHLOADER_H
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Util.h"
#include "Exc.h"
#include "Algorithm.h"

class MeshLoader {
protected:
    std::vector<Node> s_node;
    std::vector<Element> s_elem;
    std::vector<Surface> s_surf;
public:
    virtual void LoadMesh(const std::string& name_file) = 0;
    std::vector<Node> GetNode();
    std::vector<Element> GetElement();
    std::vector<Surface> GetSurface();
    std::vector<Element> FindElements(int *ID, int size);
    std::vector<Surface> FindSurfIDcond(int IDcond);
    std::vector<Element> FindElemIDmater(int ID_material);
    std::vector<Node> FindNodeIDcond(int IDcond);
    std::vector<std::pair<Node, std::vector<Node>>> NeighborElementEach();
    void OutData();
    ~MeshLoader() = default;
};

#endif //LAB1_2_MESHLOADER_H
