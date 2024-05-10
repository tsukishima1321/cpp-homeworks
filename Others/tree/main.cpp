//
//
#include "tree.hpp"
#include <iostream>

int main() {
#ifdef _WIN32
    system("chcp 65001");
#endif
    using Tree = BinaryTree<char>;
    Tree tree;
    auto it = tree.root_node();
    *it = 'A';
    tree.insertLeft(it, 'B');
    tree.insertRight(it, 'C');
    it = it.right();
    tree.insertLeft(it, 'D');
    tree.insertRight(it, 'E');

    std::cout << "Preorder traversal: ";
    for (auto &i : TreeRangePreorder<char>(tree)) {
        std::cout << i << " ";
        i += 1;
    }
    std::cout << std::endl;
    std::cout << "Modified tree: ";
    for (auto &i : TreeRangePreorder<char>(tree)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    system("pause");
    return 0;
}