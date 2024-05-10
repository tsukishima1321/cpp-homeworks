#include <concepts>

template <typename T>
class BinaryTree {
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
    template <typename _Val>
    class _FreeIterator {
        using _Self_t = _FreeIterator<_Val>;
        friend class BinaryTree;

    protected:
        TreeNode *now;
        const BinaryTree *fromTree;

    public:
        _FreeIterator(const TreeNode *root, const BinaryTree *fromTree) noexcept : fromTree(fromTree) {
            now = const_cast<TreeNode *>(root);
        }

        _FreeIterator(const _FreeIterator<const _Val> &itr) noexcept : fromTree(itr.fromTree) {
            now = const_cast<TreeNode *>(itr.now);
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

    template <typename _Val, Order_t _order>
    class _Iterator {
        using _Self_t = _Iterator<_Val, _order>;
        friend class BinaryTree;

    protected:
        TreeNode *now;
        const BinaryTree *fromTree;
        void next() {
            if constexpr (_order == PREORDER) {
                if (now == nullptr)
                    throw "OutOfRange:End";
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
            if constexpr (_order == INORDER) {
                if (now->right) {
                    now = now->right;
                    while (now->left)
                        now = now->left;
                } else if (now->parent && now == now->parent->left)
                    now = now->parent;
                else if (now->parent && now == now->parent->right) {
                    bool right_jump = true;
                    do {
                        if (now->parent->left == now) {
                            now = now->parent;
                            right_jump = false;
                            break;
                        }
                        now = now->parent;
                    } while (now->parent);
                    if (right_jump && now->parent == nullptr)
                        while (now->left)
                            now = now->left;
                } else {
                    while (now->left)
                        now = now->left;
                }
            }
            if constexpr (_order == POSTORDER) {
                if (now->parent && now->parent->right == nullptr && now->parent->left == now)
                    now = now->parent;
                else if (now->parent && now->parent->right == now)
                    now = now->parent;
                else if (now->parent && now->parent->right != nullptr && now->parent->left == now) {
                    now = now->parent->right;
                    while (now->left || now->right)
                        now = now->left == nullptr ? now->right : now->left;
                } else {
                    while (now->left || now->right)
                        now = now->left == nullptr ? now->right : now->left;
                }
            }
        }
        void last() {
            if constexpr (_order == PREORDER) {
                if (now == nullptr)
                    throw "OutOfRange:End";
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
            if constexpr (_order == INORDER) {
                if (now->left) {
                    now = now->left;
                    while (now->right)
                        now = now->right;
                } else if (now->parent) {
                    if (now == now->parent->right)
                        now = now->parent;
                    else {
                        bool left_jump = true;
                        do {
                            if (now == now->parent->right) {
                                left_jump = false;
                                now = now->parent;
                                break;
                            }
                            now = now->parent;
                        } while (now->parent);
                        if (left_jump && now->parent == nullptr)
                            while (now->right)
                                now = now->right;
                    }
                } else {
                    while (now->right)
                        now = now->right;
                }
            }
            if constexpr (_order == POSTORDER) {
                if (now->right)
                    now = now->right;
                else if (now->left)
                    now = now->left;
                else if (now->parent) {
                    do {
                        if (now->parent->left != nullptr && now->parent->right == now) {
                            now = now->parent->left;
                            break;
                        }
                        now = now->parent;
                    } while (now->parent);
                }
            }
        }

    public:
        _Iterator(const TreeNode *root, const BinaryTree *fromTree) noexcept : fromTree(fromTree) {
            now = const_cast<TreeNode *>(root);
        }

        _Iterator(const _FreeIterator<const _Val> &itr) noexcept : fromTree(itr.fromTree) {
            now = const_cast<TreeNode *>(itr.now);
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

    template <Order_t _order>
    class TreeIter {
        using _Tree = BinaryTree;
        using _TreeNode = _Tree::TreeNode;
        using _Iterator = std::conditional_t<_order == PREORDER, preorder_iterator,
                                             std::conditional_t<_order == INORDER, inorder_iterator, postorder_iterator>>;
        using _sentinel = _Tree::iterator;

    private:
        class iterator : public _Iterator {
            friend class TreeIter;

        public:
            iterator(const _TreeNode *root, const _Tree *tree) : _Iterator(root, tree), reachEnd(false) {
            }
            iterator &operator++() {
                this->next();
                if (reachEnd) {
                    this->now = nullptr;
                    return *this;
                }
                if (this->now == (*_front_of_end).now) {
                    reachEnd = true;
                }
                return *this;
            }
            iterator operator++(int) {
                iterator formal = *this;
                this->next();
                if (reachEnd) {
                    this->now = nullptr;
                    return *this;
                }
                if (this->now == (*_front_of_end).now) {
                    reachEnd = true;
                }
                return formal;
            }

        private:
            bool reachEnd;
            _sentinel *_front_of_end;
        };

    public:
        TreeIter(_Tree &tree) : _tree(tree), _begin(tree.root_node().now, &tree), _end(nullptr, &tree), _front_of_end(tree.root_node()) {
            if constexpr (_order == PREORDER) {
                while (_front_of_end.hasRight()) {
                    _front_of_end.moveRight();
                }
                while (_front_of_end.hasLeft()) {
                    _front_of_end.moveLeft();
                }
            }
            if constexpr (_order == INORDER) {
                auto begin = tree.root_node();
                while (begin.hasLeft()) {
                    begin.moveLeft();
                }
                _begin.now = begin.now;
                while (_front_of_end.hasRight()) {
                    _front_of_end.moveRight();
                }
            }
            if constexpr (_order == POSTORDER) {
                auto begin = tree.root_node();
                while (begin.hasLeft() || begin.hasRight()) {
                    while (begin.hasLeft()) {
                        begin.moveLeft();
                    }
                    if (begin.hasRight()) {
                        begin.moveRight();
                    }
                }
                _begin.now = begin.now;
                _front_of_end = tree.root_node();
            }
            _begin._front_of_end = &_front_of_end;
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
        _sentinel _front_of_end;
    };

    TreeIter<PREORDER> preIter() {
        return TreeIter<PREORDER>(*this);
    }
    TreeIter<INORDER> inIter() {
        return TreeIter<INORDER>(*this);
    }
    TreeIter<POSTORDER> postIter() {
        return TreeIter<POSTORDER>(*this);
    }
};
