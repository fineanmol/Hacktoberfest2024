#include <iostream>
#include <vector>

struct Node {
    Node *prev;
    int data;
    Node *next;

    Node(Node *prev, int data, Node *next) : prev(prev), data(data), next(next) {}

    explicit Node(int data) : Node(nullptr, data, nullptr) {}
};

class List {
    Node *first;
public:
    explicit List(const std::vector<int> &n);

    friend std::ostream &operator<<(std::ostream &os, const List &list);

    unsigned length();

    void insert(unsigned index, int value);

    void remove(unsigned short index);

    void reverse();

    virtual ~List();
};

List::List(const std::vector<int> &n) {
    first = new Node(n.at(0));
    Node *last = first, *t;

    for (int i{1}; i < n.size(); i++) {
        t = new Node(n.at(i));
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

std::ostream &operator<<(std::ostream &os, const List &list) {
    for (Node *t = list.first; t != nullptr; t = t->next)
        os << t->data << " ";
    os << std::endl;
    return os;
}

unsigned List::length() {
    int len = 0;
    for (Node *t = this->first; t != nullptr; t = t->next)
        len++;
    return len;
}

void List::insert(unsigned int index, int value) {
    Node *t;
    if (index == 0) {
        t = new Node(nullptr, value, first);
        first->prev = t;
        first = t;
    } else if (index <= this->length()) {
        Node *p = this->first;
        for (int i{0}; i < index - 1; i++)
            p = p->next;
        t = new Node(p, value, p->next);
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

void List::remove(unsigned short index) {
    if (index <= this->length() and first) {
        Node *p = first;
        if (index == 1) {
            first = first->next;
            if (first)
                first->prev = nullptr;
        } else {
            for (int i{0}; i < index - 1; i++)
                p = p->next;
            p->prev->next = p->next;
            if (p->next)
                p->next->prev = p->prev;
        }
        delete p;
    } else {
        std::cerr << "Error\n";
    }
}

void List::reverse() {
    Node *p = first, *temp;
    while (p->next) {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (!p->next and p) {
            p->next = p->prev;
            p->prev = nullptr;
            first = p;
            break;
        }
    }
}

List::~List() {
    Node *p = first;
    while (first) {
        first = first->next;
        delete p;
        p = first;
    }
}

int main() {
    vector<int> h1 = {10, 20, 30, 50, 60};
    List h(h1);
    h.insert(0, 1);
    h.insert(2, 3);
    h.insert(1, 2);
    h.insert(8, 5);
    cout << "before\n";
    cout << h;
    cout << endl;
    h.reverse();
    cout << h;
}
