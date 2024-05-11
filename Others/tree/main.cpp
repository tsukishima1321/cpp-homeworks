//
//
#include "tree.hpp"
#include <iostream>

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
    /*Tree tree;
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

    std::cout << std::endl;

    preOrderPrint(tree);
    inOrderPrint(tree);

    const Tree &ctree = tree;
    PostOrderPrint(ctree);

    tree.eraseSubTree(tree.root_node().right());

    inOrderPrint(tree);*/

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
    avl.insert(2);
    avl.insert(3);
    avl.insert(4);
    avl.insert(1);
    avl.insert(6);
    avl.insert(7);
    preOrderPrint(avl);
    inOrderPrint(avl);

    system("pause");
    return 0;
}