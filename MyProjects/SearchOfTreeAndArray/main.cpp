#include <iostream>
#include <ctime>

struct Node {
    int info;
    Node *l, *r;
};

void Add_Node(Node **q, int a) {//Построение дерева
    if (*q == NULL) {
        *q = new Node;
        (*q)->r = (*q)->l = NULL;
        (*q)->info = a;
    }
    else {
        if (a > (*q)->info) {//Условие неоходимое для построения сортированного дерева
            Add_Node(&((*q)->r), a);
        }
        else {
            Add_Node(&((*q)->l), a);
        }
    }
}

void DelNode(Node *&tree) {//Удаление дерева из памяти
    if (tree != NULL) {
        DelNode(tree->l);
        DelNode(tree->r);
        delete tree;
        tree = NULL;
    }
}

void SearchTree(Node *&tree, int& search, int &count, bool &key) {
    count++;
    if (tree) {
        if (tree->info == search) {
            std::cout << "Found " << search << " iteration " << count;
            key = true;
        }
        if (search > tree->info)
            SearchTree(tree->r, search, count, key);
        if (search < tree->info) 
            SearchTree(tree->l, search, count, key);
    }
}

void SearchArray(int *array, int size, int search, int &count) {
    count = 0;
    for (int i = 0; i < size; i++) {
        count++;
        if (array[i] == search) {
            std::cout << "Found in " << i + 1 << " position elememt " << search << std::endl;
            std::cout << "Iterations " << count << std::endl << std::endl;
            return;
        }
    }
    std::cout << "Not found "  << search << std::endl << std::endl;
}

void RandomArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        array[i] = rand() % 20 - 10;
}

int main() {
    srand(time(NULL));
    int size;
    int *array;
    int search_elem;
    int count = 0;
    bool key = false;
    system("color f2");
    std::cout << "Input size of array" << std::endl;
    std::cin >> size;
    array = new int[size];
    std::cout << "Random array" << std::endl;
    RandomArray(array, size);
    for (int i = 0; i < size; i++)
        std::cout << array[i] << ' ';
    std::cout << std::endl;
    Node *tree = NULL;
    for (int i = 0; i < size; i++)
        Add_Node(&tree, array[i]);
    std::cout << "Input element for search" << std::endl;
    std::cin >> search_elem;
    std::cout << std::endl;
    std::cout << "Search in array" << std::endl;
    SearchArray(array, size, search_elem, count);
    count = 0;
    std::cout << "Search in tree" << std::endl;
    SearchTree(tree, search_elem, count, key);
    if(!key) 
        std::cout << "Not found " << search_elem << std::endl;
    DelNode(tree);
    delete[] array;
    std::cin.ignore(); std::cin.get();
    return 0;
}