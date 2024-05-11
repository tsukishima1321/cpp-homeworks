//
//
#include "tree.hpp"
#include <iomanip>
#include <iostream>
#include <string>

using namespace BinaryTrees;

template <typename T>
void preOrderPrint(const BinaryTree<T> &tree) {
    std::cout << "Preorder traversal: ";
    for (auto &i : tree.preIter()) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void inOrderPrint(const BinaryTree<T> &tree) {
    std::cout << "Inorder traversal: ";
    for (auto &i : tree.inIter()) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void postOrderPrint(const BinaryTree<T> &tree) {
    std::cout << "Postorder traversal: ";
    for (auto &i : tree.postIter()) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}



int main() {
#ifdef _WIN32
    system("chcp 65001");
#endif
    using Tree = BinaryTree<char>;
    Tree tree;
    auto it = tree.root_node();
    it = tree.insert(it, '1');
    tree.insertLeft(it, '2');
    tree.insertRight(it, '3');
    it.moveLeft();
    tree.insertLeft(it, '4');
    tree.insertRight(it, '5');
    it.moveParent();
    it.moveRight();
    tree.insertLeft(it, '6');
    tree.insertRight(it, '7');

    // std::cout << "Tree height: " << tree.height() << std::endl;
    // std::cout << "Tree size: " << tree.size() << std::endl;

    std::cout << std::endl;
    // printTree<char>(tree.root_node());

    using SearchTree = SearchBinaryTree<int>;
    /*SearchTree stree;
    stree.insert(5);
    stree.insert(2);
    stree.insert(3);
    stree.insert(4);

    inOrderPrint(stree);
    preOrderPrint(stree);
    postOrderPrint(stree);
    auto r = stree.search(5);
    if (r) {
        std::cout << "Found: " << *r << std::endl;
        //*r = 9; // Error:不应该通过迭代器修改搜索树的值
        stree.erase(r);
        inOrderPrint(stree);
        preOrderPrint(stree);
    } else {
        std::cout << "Not found" << std::endl;
    }
    stree.erase(6);
    inOrderPrint(stree);
    preOrderPrint(stree);*/

    AVLTree<int> avl;
    avl.insert(5);
    std::cout << "Insert 5" << std::endl;
    printTree<int>(avl.root_node());
    std::cout << std::endl;
    avl.insert(2);
    std::cout << "Insert 2" << std::endl;
    printTree<int>(avl.root_node());
    std::cout << std::endl;
    avl.insert(3);
    std::cout << "Insert 3" << std::endl;
    printTree<int>(avl.root_node());
    std::cout << std::endl;
    avl.insert(4);
    std::cout << "Insert 4" << std::endl;
    printTree<int>(avl.root_node());
    std::cout << std::endl;
    avl.insert(1);
    std::cout << "Insert 1" << std::endl;
    printTree<int>(avl.root_node());
    std::cout << std::endl;
    avl.insert(6);
    std::cout << "Insert 6" << std::endl;
    printTree<int>(avl.root_node());
    std::cout << std::endl;
    avl.insert(7);
    std::cout << "Insert 7" << std::endl;
    printTree<int>(avl.root_node());
    std::cout << std::endl;
    avl.erase(5);
    std::cout << "Erase 5" << std::endl;
    printTree<int>(avl.root_node());
    std::cout << std::endl;
    avl.erase(2);
    std::cout << "Erase 2" << std::endl;
    printTree<int>(avl.root_node());
    std::cout << std::endl;
    preOrderPrint(avl);
    inOrderPrint(avl);

    system("pause");
    return 0;
}