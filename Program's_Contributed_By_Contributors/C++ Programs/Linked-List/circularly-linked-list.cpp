#include <iostream>
#include <vector>

struct Node {
    int data;
    Node *next;

    Node(int data, Node *next = nullptr) : data(data), next(next) {}
};

class Circular {
    Node *first;

public:
    explicit Circular(const std::vector<int> &arr);

    friend std::ostream &operator<<(std::ostream &os, const Circular &circular);

    void RDisplay(Node *p);

    Node *getFirst() const;

    void insert(unsigned short pos, int val);

    void remove(unsigned short pos);

    virtual ~Circular();
};

Circular::Circular(const std::vector<int> &arr) {
    first = new Node(arr.at(0));
    first->next = first;
    Node *last = first, *t;
    for (int i{1}; i < arr.size(); i++) {
        t = new Node(arr.at(i), last->next);
        last->next = t;
        last = t;
    }
}

std::ostream &operator<<(std::ostream &os, const Circular &circular) {
    Node *p = circular.first;
    do {
        os << p->data << " ";
        p = p->next;
    } while (p != circular.first);
    return os;
}

void Circular::RDisplay(Node *p) {
    static int flag{0};
    if (p != this->first || flag == 0) {
        flag = 1;
        std::cout << p->data << " ";
        RDisplay(p->next);
    }
    flag = 0;
}

Node *Circular::getFirst() const {
    return first;
}

void Circular::insert(unsigned short pos, int val) {
    if (pos != 0) {
        Node *t, *p = first;
        for (int i{0}; i < pos - 1; i++)
            p = p->next;
        t = new Node(val, p->next);
        p->next = t;
    } else {
        Node *p = first;
        Node *t = new Node(val, first);
        while (p->next != first)
            p = p->next;
        p->next = t;
        first = t;
    }
}

void Circular::remove(unsigned short pos) {
    Node *p = first;
    if (pos == 0) {
        while (p->next != first)
            p = p->next;
        if (first == p) {
            delete first;
            first = nullptr;
        } else {
            p->next = first->next;
            delete first;
            first = p->next;
        }
    } else {
        for (int i{0}; i < pos - 2; i++)
            p = p->next;
        Node *q = p->next;
        p->next = q->next;
        delete q;
    }
}

Circular::~Circular() {
    Node *temp = first;
    while (temp != nullptr) {
        Node *next = temp->next;
        delete temp;
        temp = next;
        if (temp == first) break;
    }
}

using namespace std;

int main() {
    vector<int> h = {2, 3, 4, 5, 6, 7};
    Circular s(h);
    s.insert(0, 1);
    s.insert(4, 41);
    s.insert(8, 3);
    s.remove(0);
    cout << s;
}
