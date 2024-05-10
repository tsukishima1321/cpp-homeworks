//
//
#include "tree.hpp"
#include <iostream>
#include <algorithm>

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

    std::cout << "Tree height: " << tree.height() << std::endl;
    std::cout << "Tree size: " << tree.size() << std::endl;

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
        // i += 1; //error
        std::cout << i << " ";
    }

    
    tree.eraseSubTree(tree.root_node().right());

    std::cout << "Inorder traversal: ";
    for (auto &i : tree.inIter()) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    using SearchTree = SearchBinaryTree<int>;
    SearchTree stree;
    stree.insert(5);
    stree.insert(3);
    stree.insert(7);
    stree.insert(2);
    stree.insert(4);
    stree.insert(6);
    stree.insert(8);

    std::cout << "Inorder traversal: ";
    for (auto &i : stree.inIter()) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    auto r = stree.search(5);
    if (r) {
        std::cout << "Found: " << *r << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    system("pause");
    return 0;
}