#include <concepts>

template <typename T>
class TreeRangePreorder;

template <typename T>
class BinaryTree {
    friend class TreeRangePreorder<T>;

protected:
    static bool max(const std::size_t &a, const std::size_t &b) {
        return a > b ? a : b;
    }
    class TreeNode {
    public:
        T data;
        TreeNode *left;
        TreeNode *right;
        TreeNode *parent;
        std::size_t height() {
            if (this == nullptr) {
                return 0;
            }
            return max(left->height(), right->height()) + 1;
        }
        std::size_t size() {
            if (this == nullptr) {
                return 0;
            }
            return left->size() + right->size() + 1;
        }
        TreeNode() : left(nullptr), right(nullptr), parent(nullptr) {}
        TreeNode(const T &val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
        ~TreeNode() {
            if (left != nullptr) {
                delete left;
            }
            if (right != nullptr) {
                delete right;
            }
        }
    };
    TreeNode *root;

    enum Order_t {
        PREORDER = -1,
        INORDER = 0,
        POSTORDER = 1,
    };
    template <std::totally_ordered _Val>
    class _FreeIterator {
        using _Self_t = _FreeIterator<_Val>;

    public:
        TreeNode *now;
        const BinaryTree *fromTree;
        _FreeIterator(const TreeNode *root, const BinaryTree *fromTree) noexcept : fromTree(fromTree) {
            now = const_cast<TreeNode *>(root);
        }

        _Val *operator->() const {
            return const_cast<_Val *>(&now->data);
        }

        _Val &operator*() const {
            return const_cast<_Val &>(now->data);
        }

        bool hasLeft() const {
            return now->left != nullptr;
        }
        bool hasRight() const {
            return now->right != nullptr;
        }
        bool hasParent() const {
            return now->parent != nullptr;
        }

        _Self_t &moveLeft() {
            if (now == nullptr)
                throw "OutOfRange:NoLeft";
            now = now->left;
            return *this;
        }
        _Self_t &moveRight() {
            if (now == nullptr)
                throw "OutOfRange:NoRight";
            now = now->right;
            return *this;
        }
        _Self_t &moveParent() {
            if (now == nullptr)
                throw "OutOfRange:NoParent";
            now = now->parent;
            return *this;
        }

        _Self_t left() {
            if (now == nullptr) {
                throw "OutOfRange:NoLeft";
            }
            return _Self_t(now->left, fromTree);
        }
        _Self_t right() {
            if (now == nullptr) {
                throw "OutOfRange:NoRight";
            }
            return _Self_t(now->right, fromTree);
        }
        _Self_t parent() {
            if (now == nullptr) {
                throw "OutOfRange:NoParent";
            }
            return _Self_t(now->parent, fromTree);
        }

        bool operator==(const _Self_t &itr) const {
            return now == itr.now;
        }
        bool operator!=(const _Self_t &itr) const {
            return now != itr.now;
        }
    };

    template <std::totally_ordered _Val, Order_t _Order>
    class _Iterator {
        using _Self_t = _Iterator<_Val, _Order>;

    protected:
        void next() {
            if constexpr (_Order == PREORDER) {
                if (now->left != nullptr) {
                    now = now->left;
                    return;
                }
                if (now->right != nullptr) {
                    now = now->right;
                    return;
                }
                while (now->parent != nullptr) {
                    if (now->parent->right != nullptr && now->parent->right != now) {
                        now = now->parent->right;
                        return;
                    }
                    now = now->parent;
                }
            }
            if constexpr (_Order == INORDER) {
            }
            if constexpr (_Order == POSTORDER) {
            }
        }
        void last() {
            if constexpr (_Order == PREORDER) {
                if (now->parent) {
                    if (now == now->parent->left)
                        now = now->parent;
                    else if (now == now->parent->right && now->parent->left == nullptr)
                        now = now->parent;
                    else {
                        now = now->parent->left;
                        while (now->left || now->right)
                            now = now->right == nullptr ? now->left : now->right;
                    }
                } else {
                    while (now->right)
                        now = now->right;
                }
            }
            if constexpr (_Order == INORDER) {
            }
            if constexpr (_Order == POSTORDER) {
            }
        }

    public:
        TreeNode *now;
        const BinaryTree *fromTree;
        _Iterator(const TreeNode *root, const BinaryTree *fromTree, bool init = true) noexcept : fromTree(fromTree) {
            now = const_cast<TreeNode *>(root);
            if (init) {
                if constexpr (_Order == PREORDER) {
                }
                if constexpr (_Order == INORDER) {
                }
                if constexpr (_Order == POSTORDER) {
                }
            }
        }

        operator _FreeIterator<_Val>() const {
            return _FreeIterator<_Val>(now, fromTree);
        }
        _FreeIterator<_Val> toFreeIterator() const {
            return _FreeIterator<_Val>(now, fromTree);
        }

        _Val *operator->() const {
            return const_cast<_Val *>(&now->data);
        }
        _Val &operator*() const {
            return const_cast<_Val &>(now->data);
        }
        _Self_t &operator++() {
            next();
            return *this;
        }
        _Self_t operator++(int) {
            _Self_t formal = *this;
            next();
            return formal;
        }
        _Self_t &operator--() {
            last();
            return *this;
        }
        _Self_t operator--(int) {
            _Self_t formal = *this;
            last();
            return formal;
        }

        bool operator==(const _Self_t &itr) const {
            return now == itr.now;
        }
        bool operator!=(const _Self_t &itr) const {
            return now != itr.now;
        }
    };
    using iterator = _FreeIterator<T>;
    using const_iterator = _FreeIterator<const T>;
    using preorder_iterator = _Iterator<T, PREORDER>;
    using preorder_const_iterator = _Iterator<const T, PREORDER>;
    using inorder_iterator = _Iterator<T, INORDER>;
    using inorder_const_iterator = _Iterator<const T, INORDER>;
    using postorder_iterator = _Iterator<T, POSTORDER>;
    using postorder_const_iterator = _Iterator<const T, POSTORDER>;

public:
    BinaryTree() {
        root = new TreeNode;
    }
    BinaryTree(const T &val) {
        root = new TreeNode;
        root->data = val;
    }
    ~BinaryTree() {
        if (root != nullptr) {
            delete root;
        }
    }

    std::size_t height() const {
        return root->height();
    }
    std::size_t size() const {
        return root->size();
    }

    iterator root_node() {
        return iterator(root, this);
    }
    const_iterator root_node() const {
        return const_iterator(root, this);
    }

    preorder_iterator preorder() {
        return preorder_iterator(root, this);
    }
    preorder_const_iterator const_preorder() const {
        return preorder_const_iterator(root, this);
    }
    inorder_iterator inorder() {
        return inorder_iterator(root, this);
    }
    inorder_const_iterator const_inorder() const {
        return inorder_const_iterator(root, this);
    }
    postorder_iterator postorder() {
        return postorder_iterator(root, this);
    }
    postorder_const_iterator const_postorder() const {
        return postorder_const_iterator(root, this);
    }
    preorder_iterator preorder_end() {
        return preorder_iterator(nullptr, this);
    }
    inorder_iterator inorder_end() {
        return inorder_iterator(nullptr, this);
    }
    postorder_iterator postorder_end() {
        return postorder_iterator(nullptr, this);
    }
    preorder_iterator preorder(const iterator &itr) {
        if (itr.fromTree != this)
            throw "NotFromThisTree";
        return preorder_iterator(itr.now, this);
    }
    preorder_const_iterator preorder(const const_iterator &itr) {
        if (itr.fromTree != this)
            throw "NotFromThisTree";
        return preorder_const_iterator(itr.now, this);
    }
    inorder_iterator inorder(const iterator &itr) {
        if (itr.fromTree != this)
            throw "NotFromThisTree";
        return inorder_iterator(itr.now, this);
    }
    inorder_const_iterator inorder(const const_iterator &itr) {
        if (itr.fromTree != this)
            throw "NotFromThisTree";
        return inorder_const_iterator(itr.now, this);
    }
    postorder_iterator postorder(const iterator &itr) {
        if (itr.fromTree != this)
            throw "NotFromThisTree";
        return postorder_iterator(itr.now, this);
    }
    postorder_const_iterator postorder(const const_iterator &itr) {
        if (itr.fromTree != this)
            throw "NotFromThisTree";
        return postorder_const_iterator(itr.now, this);
    }

    virtual iterator insertLeft(const iterator &itr, const T &val) {
        if (itr.fromTree != this)
            throw "NotFromThisTree";
        if (itr.now->left != nullptr)
            throw "AlreadyHasLeft";
        itr.now->left = new TreeNode(val);
        itr.now->left->parent = itr.now;
        return iterator(itr.now->left, this);
    }
    virtual iterator insertRight(const iterator &itr, const T &val) {
        if (itr.fromTree != this)
            throw "NotFromThisTree";
        if (itr.now->right != nullptr)
            throw "AlreadyHasRight";
        itr.now->right = new TreeNode(val);
        itr.now->right->parent = itr.now;
        return iterator(itr.now->right, this);
    }

    void clear(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        clear(node->left);
        clear(node->right);
        delete node;
    }

    iterator eraseSubTree(iterator &itr) {
        if (itr.fromTree != this)
            throw "NotFromThisTree";
        if (itr.now == root)
            throw "CannotEraseRoot";
        clear(itr.now);
        if (itr.now->parent != nullptr) {
            if (itr.now->parent->left == itr.now) {
                itr.now->parent->left = nullptr;
            } else {
                itr.now->parent->right = nullptr;
            }
        }
        itr.now = nullptr;
        return itr.parent();
    }
};

template <typename T>
class TreeRangePreorder {
    using _Tree = BinaryTree<T>;
    using _Iterator = _Tree::preorder_iterator;

private:
    class iterator {
    public:
        iterator(_Iterator itr, _Tree &tree) : _itr(itr), _tree(tree) {}
        iterator &operator++() {
            _itr++;
            if (_itr.toFreeIterator() == _tree.root_node()) {
                _itr = _tree.preorder_end();
            }
            return *this;
        }
        iterator operator++(int) {
            iterator formal = *this;
            _itr++;
            if (_itr.toFreeIterator() == _tree.root_node()) {
                _itr = _tree.preorder_end();
            }
            return formal;
        }
        T &operator*() {
            return *_itr;
        }
        T *operator->() {
            return _itr.operator->();
        }
        bool operator==(const iterator &itr) const {
            return _itr == itr._itr;
        }
        bool operator!=(const iterator &itr) const {
            return _itr != itr._itr;
        }

    private:
        _Iterator _itr;
        _Tree &_tree;
    };

public:
    TreeRangePreorder(_Tree &tree) : _tree(tree), _begin(tree.preorder(), tree), _end(tree.preorder_end(), tree) {
    }
    iterator begin() {
        return _begin;
    }
    iterator end() {
        return _end;
    }

    _Tree &_tree;
    iterator _begin;
    iterator _end;
};
