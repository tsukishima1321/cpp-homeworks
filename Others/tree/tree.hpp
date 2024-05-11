#include <cmath>
#include <concepts>

template <typename T>
class BinaryTree {
protected:
    static std::size_t max(const std::size_t &a, const std::size_t &b) {
        return a > b ? a : b;
    }
    class TreeNode {
    public:
        T data;
        TreeNode *left;
        TreeNode *right;
        TreeNode *parent;
        std::size_t height() {
            return max(left ? left->height() : 0, right ? right->height() : 0) + 1;
        }
        std::size_t size() {
            return (left ? left->size() : 0) + (right ? right->size() : 0) + 1;
        }
        TreeNode() : left(nullptr), right(nullptr), parent(nullptr), data() {}
        TreeNode(const T &val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
        ~TreeNode() {
            if (left != nullptr) {
                delete left;
                left = nullptr;
            }
            if (right != nullptr) {
                delete right;
                right = nullptr;
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
    public:
        TreeNode *now;
        const BinaryTree *fromTree;
        _FreeIterator(const TreeNode *root, const BinaryTree *fromTree) noexcept : fromTree(fromTree) {
            now = const_cast<TreeNode *>(root);
        }

        _FreeIterator(const _FreeIterator<const _Val> &itr) noexcept : fromTree(itr.fromTree) {
            now = const_cast<TreeNode *>(itr.now);
        }

        operator bool() const {
            return now != nullptr;
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
        _Iterator(const _Iterator &itr) noexcept : fromTree(itr.fromTree) {
            now = itr.now;
        }
        _Iterator(_Iterator &&itr) noexcept : fromTree(itr.fromTree) {
            now = itr.now;
            itr.now = nullptr;
        }

        ~_Iterator() = default;

        operator bool() const {
            return now != nullptr;
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

public:
    using iterator = _FreeIterator<T>;
    using const_iterator = _FreeIterator<const T>;
    using preorder_iterator = _Iterator<T, PREORDER>;
    using preorder_const_iterator = _Iterator<const T, PREORDER>;
    using inorder_iterator = _Iterator<T, INORDER>;
    using inorder_const_iterator = _Iterator<const T, INORDER>;
    using postorder_iterator = _Iterator<T, POSTORDER>;
    using postorder_const_iterator = _Iterator<const T, POSTORDER>;
    BinaryTree() : root(nullptr) {}
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
    preorder_const_iterator preorder(const const_iterator &itr) const {
        if (itr.fromTree != this)
            throw "NotFromThisTree";
        return preorder_const_iterator(itr.now, this);
    }
    inorder_iterator inorder(const iterator &itr) {
        if (itr.fromTree != this)
            throw "NotFromThisTree";
        return inorder_iterator(itr.now, this);
    }
    inorder_const_iterator inorder(const const_iterator &itr) const {
        if (itr.fromTree != this)
            throw "NotFromThisTree";
        return inorder_const_iterator(itr.now, this);
    }
    postorder_iterator postorder(const iterator &itr) {
        if (itr.fromTree != this)
            throw "NotFromThisTree";
        return postorder_iterator(itr.now, this);
    }
    postorder_const_iterator postorder(const const_iterator &itr) const {
        if (itr.fromTree != this)
            throw "NotFromThisTree";
        return postorder_const_iterator(itr.now, this);
    }

    iterator insertLeft(const iterator &itr, const T &val) {
        if (itr.fromTree != this)
            throw "NotFromThisTree";
        if (itr.now->left != nullptr)
            throw "AlreadyHasLeft";
        itr.now->left = new TreeNode(val);
        itr.now->left->parent = itr.now;
        return iterator(itr.now->left, this);
    }
    iterator insertRight(const iterator &itr, const T &val) {
        if (itr.fromTree != this)
            throw "NotFromThisTree";
        if (itr.now->right != nullptr)
            throw "AlreadyHasRight";
        itr.now->right = new TreeNode(val);
        itr.now->right->parent = itr.now;
        return iterator(itr.now->right, this);
    }

    virtual iterator insert(const iterator &itr, const T &val) {
        if (itr.fromTree != this)
            throw "NotFromThisTree";
        if (itr.now == nullptr && root == nullptr) {
            root = new TreeNode(val);
            return iterator(root, this);
        }
        if (itr.now->left == nullptr) {
            itr.now->left = new TreeNode(val);
            itr.now->left->parent = itr.now;
            return iterator(itr.now->left, this);
        }
        if (itr.now->right == nullptr) {
            itr.now->right = new TreeNode(val);
            itr.now->right->parent = itr.now;
            return iterator(itr.now->right, this);
        }
        throw "AlreadyHasTwoChildren";
    }

    void clear(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        if (node->left != nullptr) {
            delete node->left;
        }
        if (node->right != nullptr) {
            delete node->right;
        }
        return;
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

    iterator eraseSubTree(iterator &&itr) {
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
        return itr.parent();
    }

    template <Order_t _order, typename _Val>
    class TreeIter {
        using _Tree = BinaryTree;
        using _TreeNode = _Tree::TreeNode;
        using _Iterator = _Iterator<_Val, _order>;
        using _Sentinel = _Tree::iterator;

    protected:
        class iterator : public _Iterator {
            friend class TreeIter;

        public:
            iterator(const _TreeNode *root, const _Tree *tree) : _Iterator(root, tree), reachEnd(false) {}
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

        protected:
            bool reachEnd;
            const _Sentinel *_front_of_end;
        };

    public:
        TreeIter(const _Tree &tree) : _tree(tree), _begin(tree.root_node().now, &tree), _end(nullptr, &tree), _front_of_end(tree.root_node()) {
            auto begin = tree.root_node();
            if constexpr (_order == PREORDER) {
                while (_front_of_end.hasRight() || _front_of_end.hasLeft()) {
                    if (_front_of_end.hasRight()) {
                        _front_of_end.moveRight();
                    } else {
                        _front_of_end.moveLeft();
                    }
                }
            }
            if constexpr (_order == INORDER) {
                while (begin.hasLeft()) {
                    begin.moveLeft();
                }
                while (_front_of_end.hasRight()) {
                    _front_of_end.moveRight();
                }
            }
            if constexpr (_order == POSTORDER) {
                while (begin.hasLeft() || begin.hasRight()) {
                    while (begin.hasLeft()) {
                        begin.moveLeft();
                    }
                    if (begin.hasRight()) {
                        begin.moveRight();
                    }
                }
                _front_of_end = tree.root_node();
            }
            _begin.now = begin.now;
            _begin._front_of_end = &_front_of_end;
        }
        iterator begin() {
            return _begin;
        }
        iterator end() {
            return _end;
        }

    protected:
        const _Tree &_tree;
        iterator _begin;
        iterator _end;
        _Sentinel _front_of_end;
    };

    using PreorderIter = TreeIter<PREORDER, T>;
    using InorderIter = TreeIter<INORDER, T>;
    using PostorderIter = TreeIter<POSTORDER, T>;
    using PreorderIterConst = TreeIter<PREORDER, const T>;
    using InorderIterConst = TreeIter<INORDER, const T>;
    using PostorderIterConst = TreeIter<POSTORDER, const T>;

    PreorderIter preIter() {
        return PreorderIter(*this);
    }
    InorderIter inIter() {
        return InorderIter(*this);
    }
    PostorderIter postIter() {
        return PostorderIter(*this);
    }
    PreorderIterConst preIter() const {
        return PreorderIterConst(*this);
    }
    InorderIterConst inIter() const {
        return InorderIterConst(*this);
    }
    PostorderIterConst postIter() const {
        return PostorderIterConst(*this);
    }
    PreorderIterConst preIterConst() {
        return PreorderIterConst(*this);
    }
    InorderIterConst inIterConst() {
        return InorderIterConst(*this);
    }
    PostorderIterConst postIterConst() {
        return PostorderIterConst(*this);
    }
};

template <std::totally_ordered T>
class SearchBinaryTree : public BinaryTree<T> {
public:
    using BinaryTree<T>::BinaryTree;
    using _Iterator = BinaryTree<T>::iterator;
    using _Node = BinaryTree<T>::TreeNode;
    class iterator : public _Iterator {
        friend class SearchBinaryTree;
        using _Iterator::_Iterator;

    public:
        iterator(_Iterator &itr) : _Iterator(itr) {}
        iterator(_Iterator &&itr) : _Iterator(itr) {}
        const T *operator->() {
            return &this->now->data;
        }
        const T &operator*() {
            return this->now->data;
        }
    };
    iterator insertLeft(const iterator &itr, const T &val) { throw "NotImplemented"; }
    iterator insertRight(const iterator &itr, const T &val) { throw "NotImplemented"; }
    iterator eraseSubTree(iterator &itr) = delete;
    iterator eraseSubTree(iterator &&itr) = delete;
    virtual bool insert(const T &val) {
        if (this->root == nullptr) {
            this->root = new _Node(val);
            return true;
        }
        auto now = this->root;
        while (true) {
            if (val < now->data) {
                if (now->left == nullptr) {
                    now->left = new _Node(val);
                    now->left->parent = now;
                    return true;
                }
                now = now->left;
            } else if (val > now->data) {
                if (now->right == nullptr) {
                    now->right = new _Node(val);
                    now->right->parent = now;
                    return true;
                }
                now = now->right;
            } else {
                return false;
            }
        }
    }
    iterator search(const T &val) {
        auto now = this->root;
        while (now != nullptr) {
            if (val < now->data) {
                now = now->left;
            } else if (val > now->data) {
                now = now->right;
            } else {
                return iterator(now, this);
            }
        }
        return iterator(nullptr, this);
    }
    virtual bool erase(iterator &itr) {
        if (itr.fromTree != this)
            throw "NotFromThisTree";
        if (itr.now->left == nullptr && itr.now->right == nullptr) {
            if (!itr.hasParent()) {
                this->root = nullptr;
                delete itr.now;
                return true;
            }
            if (itr.now->parent->left == itr.now) {
                itr.now->parent->left = nullptr;
            } else {
                itr.now->parent->right = nullptr;
            }
            auto parent = itr.parent();
            delete itr.now;
            return true;
        }
        if (itr.now->left == nullptr) {
            if (!itr.hasParent()) {
                itr.now->right->parent = nullptr;
                this->root = itr.now->right;
                itr.now->right = nullptr;
                delete itr.now;
                return true;
            }
            if (itr.now->parent->left == itr.now) {
                itr.now->parent->left = itr.now->right;
            } else {
                itr.now->parent->right = itr.now->right;
            }
            itr.now->right->parent = itr.now->parent;
            itr.now->right = nullptr;
            delete itr.now;
            return true;
        }
        if (itr.now->right == nullptr) {
            if (!itr.hasParent()) {
                itr.now->left->parent = nullptr;
                this->root = itr.now->left;
                itr.now->left = nullptr;
                delete itr.now;
                return true;
            }
            if (itr.now->parent->left == itr.now) {
                itr.now->parent->left = itr.now->left;
            } else {
                itr.now->parent->right = itr.now->left;
            }
            itr.now->left->parent = itr.now->parent;
            itr.now->left = nullptr;
            delete itr.now;
            return true;
        }
        iterator next = this->_find_min_in_right(itr);
        itr.now->data = next.now->data;
        erase(next);
        return itr.parent();
    }
    virtual bool erase(const T &val) {
        auto itr = search(val);
        if (itr) {
            return erase(itr);
        }
        return false;
    }

protected:
    static iterator _find_min_in_right(iterator itr) {
        if (!itr.hasRight()) {
            throw "OutOfRange:NoRight";
        }
        itr.moveRight();
        while (itr.hasLeft()) {
            itr.moveLeft();
        }
        return itr;
    }
};

template <typename T>
concept copy_and_compare = std::copy_constructible<T> &&std::totally_ordered<T>;

template <copy_and_compare T>
class AVLTree : public SearchBinaryTree<T> {
public:
    using SearchBinaryTree<T>::SearchBinaryTree;
    using SearchBinaryTree<T>::search;
    using SearchBinaryTree<T>::_find_min_in_right;
    using _Node = SearchBinaryTree<T>::TreeNode;
    using _Iterator = SearchBinaryTree<T>::iterator;
    using iterator = _Iterator;
    class AVLNode : public _Node {
        using _Node::_Node;

    public:
        int depth;
        AVLNode() : _Node(), depth(1) {}
        AVLNode(const T &val) : _Node(val), depth(1) {}
    };
    virtual bool insert(const T &val) override {
        auto it = search(val);
        if (it) {
            return false;
        }
        if (this->root == nullptr) {
            this->root = new AVLNode(val);
            return iterator(this->root, this);
        }
        _Node *now = this->root;
        now = _insert_recursive((AVLNode *)now, val);
        return true;
    }
    virtual bool erase(iterator &itr) override {
        if (itr.fromTree != this)
            throw "NotFromThisTree";
        if (itr.now == nullptr) {
            return false;
        }
        auto exist = search(*itr);
        if (!exist) {
            return false;
        }
        _Node *now = this->root;
        now = _delete_recursive((AVLNode *)now, T(*itr));
        return true;
    }
    virtual bool erase(const T &val) override {
        auto it = search(val);
        if (!it) {
            return false;
        }
        _Node *now = this->root;
        now = _delete_recursive((AVLNode *)now, val);
        return true;
    }

protected:
    std::size_t _height(AVLNode *node) {
        return node ? node->depth : 0;
    }
    void _update_height(AVLNode *node) {
        if (node) {
            node->depth = BinaryTree<T>::max(_height((AVLNode *)node->left), _height((AVLNode *)node->right)) + 1;
        }
    }
    AVLNode *_insert_recursive(AVLNode *node, const T &val) {
        if (node == nullptr) {
            return new AVLNode(val);
        }
        if (val < node->data) {
            node->left = _insert_recursive((AVLNode *)node->left, val);
            node->left->parent = node;
        } else if (val > node->data) {
            node->right = _insert_recursive((AVLNode *)node->right, val);
            node->right->parent = node;
        } else {
            return node;
        }
        _update_height(node);
        return _maintain(node);
    }
    AVLNode *_delete_recursive(AVLNode *node, const T &val) {
        if (node == nullptr) {
            return nullptr;
        }
        if (val < node->data) {
            node->left = _delete_recursive((AVLNode *)node->left, val);
            if (node->left) {
                node->left->parent = node;
            }
        } else if (val > node->data) {
            node->right = _delete_recursive((AVLNode *)node->right, val);
            if (node->right) {
                node->right->parent = node;
            }
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            if (node->left == nullptr) {
                AVLNode *right = (AVLNode *)node->right;
                node->right = nullptr;
                delete node;
                return right;
            }
            if (node->right == nullptr) {
                AVLNode *left = (AVLNode *)node->left;
                node->left = nullptr;
                delete node;
                return left;
            }
            AVLNode *next = (AVLNode *)_find_min_in_right(iterator((_Node *)node, this)).now;
            std::swap(node->data, next->data);
            node->right = _delete_recursive((AVLNode *)node->right, val);
            if (node->right) {
                node->right->parent = node;
            }
        }
        _update_height(node);
        return _maintain(node);
    }
    AVLNode *_rotate_left(AVLNode *node) {
        AVLNode *right = (AVLNode *)node->right;
        node->right = right->left;
        if (right->left) {
            right->left->parent = node;
        }
        right->left = node;
        right->parent = node->parent;
        if (right->parent == nullptr) {
            this->root = right;
        }
        node->parent = right;
        _update_height(node);
        _update_height(right);
        return right;
    }
    AVLNode *_rotate_right(AVLNode *node) {
        AVLNode *left = (AVLNode *)node->left;
        node->left = left->right;
        if (left->right) {
            left->right->parent = node;
        }
        left->right = node;
        left->parent = node->parent;
        if (left->parent == nullptr) {
            this->root = left;
        }
        node->parent = left;
        _update_height(node);
        _update_height(left);
        return left;
    }
    AVLNode *_maintain(AVLNode *node) {
        if (node == nullptr) {
            return nullptr;
        }
        int leftHeight = _height((AVLNode *)node->left);
        int rightHeight = _height((AVLNode *)node->right);
        if (std::abs(leftHeight - rightHeight) > 1) {
            if (leftHeight > rightHeight) {
                int leftLeftHeight = _height((AVLNode *)node->left->left);
                int leftRightHeight = _height((AVLNode *)node->left->right);
                if (leftLeftHeight >= leftRightHeight) {
                    node = _rotate_right(node);
                } else {
                    node->left = _rotate_left((AVLNode *)node->left);
                    node = _rotate_right(node);
                }
            } else {
                int rightLeftHeight = _height((AVLNode *)node->right->left);
                int rightRightHeight = _height((AVLNode *)node->right->right);
                if (rightRightHeight >= rightLeftHeight) {
                    node = _rotate_left(node);
                } else {
                    node->right = _rotate_right((AVLNode *)node->right);
                    node = _rotate_left(node);
                }
            }
        }
        return node;
    }
};