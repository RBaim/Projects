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
    std::cout << "find" << std::endl;
    for(int i = 0; i < f.size(); ++i) {
        for(int j = 0; j < f[i].ID_node.Size(); ++j)
            std::cout << f[i].ID_node[j] << ' ';
        std::cout << std::endl;
    }
    delete n;
    system("pause");
    return 0;
}