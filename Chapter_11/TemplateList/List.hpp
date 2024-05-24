#include <iostream>

namespace MyList {
    template <typename T>
    class List {
    public:
        List() : head(nullptr){};
        ~List(){
            Node *p = head, *q;
            while (p != nullptr) {
                q = p->next;
                delete p;
                p = q;
            }
        };
        void push_back(const T &data) {
            if (head == nullptr) {
                head = new Node;
                head->data = data;
                head->next = nullptr;
                head->last = nullptr;
                return;
            }
            Node *p = head;
            while (p->next != nullptr) {
                p = p->next;
            }
            Node *q = new Node;
            q->data = data;
            q->next = nullptr;
            q->last = p;
            p->next = q;
        };
        void push_front(const T &data) {
            if (head == nullptr) {
                head = new Node;
                head->data = data;
                head->next = nullptr;
                head->last = nullptr;
                return;
            }
            Node *q = new Node;
            q->data = data;
            q->next = head;
            head->last = q;
            q->last = nullptr;
            head = q;
        };
        void pop_back() {
            Node *p = head;
            while (p->next->next != nullptr) {
                p = p->next;
            }
            delete p->next;
            p->next = nullptr;
        };
        void pop_front() {
            Node *p = head;
            head = head->next;
            head->last = nullptr;
            delete p;
        };
        std::size_t size() const {
            std::size_t count = 0;
            Node *p = head;
            while (p->next != nullptr) {
                count++;
                p = p->next;
            }
            return count;
        };
        template <typename _Val>
        class _Iterator;
        friend class _Iterator<T>;

    protected:
        struct Node {
            T data;
            Node *next;
            Node *last;
        };
        Node *head;

    public:
        template <typename _Val>
        class _Iterator {
        public:
            _Iterator() = delete;
            _Iterator &operator++() {
                now = now->next;
                return *this;
            };
            _Iterator operator++(int) {
                _Iterator temp = *this;
                now = now->next;
                return temp;
            };
            _Iterator &operator--() {
                now = now->last;
                return *this;
            };
            _Iterator operator--(int) {
                _Iterator temp = *this;
                now = now->last;
                return temp;
            };
            _Val &operator*() {
                return now->data;
            };
            _Val *operator->() {
                return &now->data;
            };
            bool operator==(const _Iterator &rhs) const {
                return now == rhs.now;
            };
            bool operator!=(const _Iterator &rhs) const {
                return now != rhs.now;
            };

        private:
            friend class List;
            _Iterator(List<_Val> *list, std::size_t index) {
                this->list = list;
                now = list->head;
                for (std::size_t i = 0; i < index; i++) {
                    now = now->next;
                }
            };
            _Iterator(const _Iterator &it) {
                list = it.list;
                now = it.now;
            };
            _Iterator(_Iterator &&it) {
                list = it.list;
                now = it.now;
                it.list = nullptr;
                it.now = nullptr;
            };
            _Iterator(List<_Val> *list, Node *now) {
                this->list = list;
                this->now = now;
            };
            List<_Val> *list;
            Node *now;
        };
        using Iterator = _Iterator<T>;
        Iterator begin() {
            return Iterator(this, std::size_t(0));
        };
        Iterator end() {
            return Iterator(this, size());
        };
    };
}