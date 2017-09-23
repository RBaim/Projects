#include <iostream>
#include "AneuMeshLoader.h"

int main(int argc, char* argv[]) {
    std::cout << "argc: " << argc << std::endl;
    for (int i = 0; i < argc; i++) {
        std::cout << "Argument " << i << " : " << argv[i] << std::endl;
    }
    MeshLoader* n  = new AneuMeshLoader;
    if(argc > 1) {
        n->LoadMesh(argv[1]);
        
    }
    else {
        std::string in;
        std::cin >> in;
        n->LoadMesh(in);
    }
    n->OutData();
    int *ID = new int[2] {1, 3};
    std::vector<Element> f = (n->FindElements(ID, 2));
    std::cout << "find of {1, 3}" << std::endl;
    for(int i = 0; i < f.size(); ++i) {
        for(int j = 0; j < f[i].ID_node.size(); ++j)
            std::cout << f[i].ID_node[j] << ' ';
        std::cout << std::endl;
    }
    std::cout << "Neighbor" << std::endl;
    auto sear = n->NeighborElementEach();
    for(int i = 0; i < sear.size(); ++i) {
        std::cout << std::setw(4) << i + 1 << '(';
        for(int j = 0; j < sear[i].size(); ++j)
            std::cout << ' ' << sear[i][j];
        std::cout << " )" << std::endl;
    }
    std::cout << "FindNodeIDcond(3)" << std::endl;
    auto s1 = n->FindNodeIDcond(3);
    for(int i = 0; i < s1.size(); ++i)
        std::cout << std::setw(5) << s1[i];
    std::cout << std::endl;
    n->Modify();
    std::cout << "Modify" << std::endl;
    n->OutData();
    delete n;
    system("pause");
    return 0;
}