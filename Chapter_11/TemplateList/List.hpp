#include <utility>

namespace MyList {
    template <typename T>
    class List {
    public:
        List() : head(nullptr){};
        ~List() {
            Node *p = head, *q;
            while (p != nullptr) {
                q = p->next;
                delete p;
                p = q;
            }
        }
        List(const List &list) : head(nullptr) {
            Node *p = list.head;
            while (p != nullptr) {
                push_back(p->data);
                p = p->next;
            }
        }
        List(List &&list) {
            head = list.head;
            list.head = nullptr;
        }
        List &operator=(const List &list) {
            if (this == &list) {
                return *this;
            }
            Node *p = head, *q;
            while (p != nullptr) {
                q = p->next;
                delete p;
                p = q;
            }
            head = nullptr;
            p = list.head;
            while (p != nullptr) {
                push_back(p->data);
                p = p->next;
            }
            return *this;
        }
        List &operator=(List &&list) {
            if (this == &list) {
                return *this;
            }
            Node *p = head, *q;
            while (p != nullptr) {
                q = p->next;
                delete p;
                p = q;
            }
            head = list.head;
            list.head = nullptr;
            return *this;
        }
        List(std::initializer_list<T> list) : head(nullptr) {
            for (auto &i : list) {
                push_back(i);
            }
        }
        List(T *start, T *end) : head(nullptr) {
            for (T *i = start; i != end; i++) {
                push_back(*i);
            }
        }
        void push_back(auto &&data) {
            if (head == nullptr) {
                head = new Node(std::forward<decltype(data)>(data));
                return;
            }
            Node *p = head;
            while (p->next != nullptr) {
                p = p->next;
            }
            Node *q = new Node(std::forward<decltype(data)>(data), nullptr, p);
            p->next = q;
        }
        void push_front(auto &&data) {
            if (head == nullptr) {
                head = new Node(std::forward<decltype(data)>(data));
                return;
            }
            Node *q = new Node(std::forward<decltype(data)>(data), head, nullptr);
            head->last = q;
            head = q;
        }
        void pop_back() {
            Node *p = head;
            while (p->next->next != nullptr) {
                p = p->next;
            }
            delete p->next;
            p->next = nullptr;
        }
        void pop_front() {
            Node *p = head;
            head = head->next;
            head->last = nullptr;
            delete p;
        }
        std::size_t size() const {
            std::size_t count = 0;
            Node *p = head;
            while (p->next != nullptr) {
                count++;
                p = p->next;
            }
            return count;
        }

    protected:
        template <typename _Val>
        class _Iterator;
        friend class _Iterator<T>;

    protected:
        class Node {
        public:
            T data;
            Node *next;
            Node *last;
            Node() = delete;
            Node(auto &&data, Node *next = nullptr, Node *last = nullptr) : data(std::forward<decltype(data)>(data)), next(next), last(last){};
        };
        Node *head;

        template <typename _Val>
        class _Iterator {
        public:
            _Iterator() = delete;
            _Iterator &operator++() {
                now = now->next;
                return *this;
            }
            _Iterator operator++(int) {
                _Iterator temp = *this;
                now = now->next;
                return temp;
            }
            _Iterator &operator--() {
                now = now->last;
                return *this;
            }
            _Iterator operator--(int) {
                _Iterator temp = *this;
                now = now->last;
                return temp;
            }
            _Val &operator*() {
                return now->data;
            }
            _Val *operator->() {
                return &now->data;
            }
            bool operator==(const _Iterator &rhs) const {
                return now == rhs.now;
            }
            bool operator!=(const _Iterator &rhs) const {
                return now != rhs.now;
            }

        private:
            friend class List;
            _Iterator(List<_Val> *list, std::size_t index) {
                this->list = list;
                now = list->head;
                for (std::size_t i = 0; i < index; i++) {
                    now = now->next;
                }
            }
            _Iterator(const _Iterator &it) {
                list = it.list;
                now = it.now;
            }
            _Iterator(_Iterator &&it) {
                list = it.list;
                now = it.now;
                it.list = nullptr;
                it.now = nullptr;
            }
            _Iterator(List<_Val> *list, Node *now) {
                this->list = list;
                this->now = now;
            }
            List<_Val> *list;
            Node *now;
        };

    public:
        using Iterator = _Iterator<T>;
        Iterator begin() {
            return Iterator(this, std::size_t(0));
        }
        Iterator end() {
            return Iterator(this, nullptr);
        }
        Iterator erase(Iterator it) {
            if (it.now == head) {
                head = head->next;
                head->last = nullptr;
                delete it.now;
                return Iterator(this, head);
            }
            Node *p = it.now->last;
            p->next = it.now->next;
            if (it.now->next != nullptr) {
                it.now->next->last = p;
            }
            delete it.now;
            return Iterator(this, p->next);
        }
        Iterator insert(Iterator it, auto &&data) { // insert after it
            Node *p = new Node(std::forward<decltype(data)>(data), it.now->next, it.now);
            it.now->next = p;
            if (p->next != nullptr) {
                p->next->last = p;
            }
            return Iterator(this, p);
        }
    };
}