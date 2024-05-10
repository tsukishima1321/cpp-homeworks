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
    *it = '1';
    tree.insertLeft(it, '2');
    tree.insertRight(it, '3');
    it.moveLeft();
    tree.insertLeft(it, '4');
    tree.insertRight(it, '5');
    it.moveParent();
    it.moveRight();
    tree.insertLeft(it, '6');
    tree.insertRight(it, '7');

    std::cout << "Preorder traversal: ";
    for (auto &i : tree.preIter()) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Inorder traversal: ";
    for (auto &i : tree.inIter()) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    for (auto const &i : tree.postIterConst()) {
        // i += 1; //error
        std::cout << i << " ";
    }
    std::cout << std::endl;

    const Tree &ctree = tree;
    std::cout << "Postorder traversal: ";
    for (auto &i : ctree.postIter()) {
        //i += 1; //error
        std::cout << i << " ";
    }

    tree.eraseSubTree(tree.root_node().right());

    std::cout << "Inorder traversal: ";
    for (auto &i : tree.inIter()) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    system("pause");
    return 0;
}