#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* next;

    Node(int data, Node* next) : data(data), next(next) {}

    explicit Node(int data) : Node(data, nullptr) {}

    Node() : Node(0, nullptr) {}
};

class List {
    Node* head;

public:
    explicit List(int x) : head(new Node(x)) {}

    explicit List(Node* head) : head(head) {}

    explicit List(std::vector<int> array) {
        if (array.empty()) {
            head = nullptr;
        } else {
            head = new Node(array[0]);
            Node* current = head;
            for (int i = 1; i < array.size(); i++) {
                current->next = new Node(array[i]);
                current = current->next;
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const List& list) {
        Node* current = list.head;
        while (current) {
            os << current->data << " -> ";
            current = current->next;
        }
        os << "nullptr";
        return os;
    }

    void display_R(Node* p) {
        if (p) {
            std::cout << p->data << " -> ";
            display_R(p->next);
        } else {
            std::cout << "nullptr";
        }
    }

    int count() {
        return count_R(head);
    }

    static int count_R(Node* p) {
        if (!p) {
            return 0;
        }
        return 1 + count_R(p->next);
    }

    int sum() {
        return sum_R(head);
    }

    static int sum_R(Node* p) {
        if (!p) {
            return 0;
        }
        return p->data + sum_R(p->next);
    }

    int max() {
        return max_R(head);
    }

    static int max_R(Node* p) {
        if (!p) {
            return std::numeric_limits<int>::min();
        }
        return std::max(p->data, max_R(p->next));
    }

    int search(int key) {
        return search_R(head, key);
    }

    static int search_R(Node* p, int key) {
        if (!p) {
            return -1;
        }
        if (p->data == key) {
            return 0;
        }
        int result = search_R(p->next, key);
        return (result == -1) ? -1 : 1 + result;
    }

    Node* getHead() const {
        return head;
    }

    void insert(unsigned short index, int val) {
        if (index == 0) {
            head = new Node(val, head);
            return;
        }
        Node* current = head;
        for (int i = 0; i < index - 1 && current; i++) {
            current = current->next;
        }
        if (current) {
            current->next = new Node(val, current->next);
        }
    }

    void append(int val) {
        if (!head) {
            head = new Node(val);
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new Node(val);
    }

    void SortedInsert(int val) {
        if (!head || head->data > val) {
            head = new Node(val, head);
            return;
        }
        Node* current = head;
        while (current->next && current->next->data < val) {
            current = current->next;
        }
        current->next = new Node(val, current->next);
    }

    void remove(unsigned short index) {
        if (index == 0) {
            if (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            return;
        }
        Node* current = head;
        for (int i = 0; i < index - 1 && current; i++) {
            current = current->next;
        }
        if (current && current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    bool sorted() {
        Node* current = head;
        while (current && current->next) {
            if (current->data > current->next->data) {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    void remove_sorted() {
        Node* current = head;
        while (current && current->next) {
            if (current->data == current->next->data) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }

    std::vector<int> get_list() {
        std::vector<int> result;
        Node* current = head;
        while (current) {
            result.push_back(current->data);
            current = current->next;
        }
        return result;
    }

    void reverse_1() {
        if (!head || !head->next) {
            return;
        }
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void reverse_2() {
        if (!head || !head->next) {
            return;
        }
        Node* prev = nullptr;
        Node* current = head;
        Node* next = head->next;
        while (next) {
            current->next = prev;
            prev = current;
            current = next;
            next = next->next;
        }
        current->next = prev;
        head = current;
    }

    void reverse_R(Node* q, Node* p) {
        if (p) {
            reverse_R(p, p->next);
            p->next = q;
        } else {
            head = q;
        }
    }

    static void concat(Node* h1, Node* h2) {
        Node* current = h1;
        while (current->next) {
            current = current->next;
        }
        current->next = h2;
    }

    List merge(Node* second) {
        Node* mergedHead = nullptr;
        Node* tail = nullptr;
        Node* p1 = head;
        Node* p2 = second;

        while (p1 && p2) {
            if (p1->data <= p2->data) {
                if (!mergedHead) {
                    mergedHead = p1;
                    tail = p1;
                } else {
                    tail->next = p1;
                    tail = p1;
                }
                p1 = p1->next;
            } else {
                if (!mergedHead) {
                    mergedHead = p2;
                    tail = p2;
                } else {
                    tail->next = p2;
                    tail = p2;
                }
                p2 = p2->next;
            }
        }

        if (p1) {
            tail->next = p1;
        } else if (p2) {
            tail->next = p2;
        }

        return List(mergedHead);
    }

    bool hasLoop() {
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }

    virtual ~List() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    List myList({1, 2, 3, 4, 5});

    std::cout << "Original List: " << myList << std::endl;

    std::cout << "Count: " << myList.count() << std::endl;
    std::cout << "Sum: " << myList.sum() << std::endl;
    std::cout << "Max: " << myList.max() << std::endl;
    std::cout << "Search for 3: " << myList.search(3) << std::endl;

    myList.insert(2, 6);
    myList.append(7);
    myList.SortedInsert(2);
    myList.remove(4);

    std::cout << "Modified List: " << myList << std::endl;
    std::cout << "Is Sorted: " << myList.sorted() << std::endl;

    myList.reverse_1();
    std::cout << "Reversed List (Method 1): " << myList << std::endl;

    myList.reverse_2();
    std::cout << "Reversed List (Method 2): " << myList << std::endl;

    List list2({0, 2, 3, 8});
    List::concat(myList.getHead(), list2.getHead());

    std::cout << "Concatenated List: " << myList << std::endl;

    List mergedList = myList.merge(list2.getHead());
    std::cout << "Merged List: " << mergedList << std::endl;

    std::cout << "Has Loop: " << myList.hasLoop() << std::endl;

    return 0;
}
