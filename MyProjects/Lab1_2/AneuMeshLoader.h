//
// Created by radmi on 06.09.2017.
//

#ifndef LAB1_2_ANEUMESHLOADER_H
#define LAB1_2_ANEUMESHLOADER_H

#include "MeshLoader.h"

class AneuMeshLoader : public MeshLoader {
public:
    void LoadMesh(const std::string& name_file) override ;
};


#endif //LAB1_2_ANEUMESHLOADER_H
