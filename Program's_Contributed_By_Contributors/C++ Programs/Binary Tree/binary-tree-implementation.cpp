#include <iostream>
#include <algorithm>
#include <exception>
#include <string>

using dType = int;

template <typename T>
struct Node
{
    T val;
    Node<T>* rightNode;
    Node<T>* leftNode;
};

template <class T>
class BinaryTree
{
private:
    Node<T>* root = nullptr;

    static int getHeight(Node<T>* root)
    {
        if (!root)
            return 0;

        return 1 + std::max(getHeight(root->leftNode), getHeight(root->rightNode));
    }

    static const std::string print(Node<T>* node)
    {
        if (!node)
            return "Empty";
        return "" + std::to_string(node->val) + " (" + print(node->leftNode) + ") (" + print(node->rightNode) + ")";
    }

public:
    BinaryTree() {}

    void insert(T val)
    {
        Node<T>* newNode { new Node<T>[sizeof(Node<T>)] };
        newNode->val = val;
        newNode->rightNode = nullptr;
        newNode->leftNode = nullptr;

        if (!root)
        {
            root = newNode;
            return;
        }

        Node<T>* currNode = root;
        while (currNode)
        {
            T oldVal = currNode->val;
            if (val > oldVal)
            {
                if (currNode->rightNode)
                {
                    currNode = currNode->rightNode;
                    continue;
                }
                currNode->rightNode = newNode;
                break;
            }
            else if (val < oldVal)
            {
                if (currNode->leftNode)
                {
                    currNode = currNode->leftNode;
                    continue;
                }
                currNode->leftNode = newNode;
                break;
            }
            else
                throw std::runtime_error("Duplicate value.");
        }
    }

    int height()
    {
        return getHeight(root);
    }

    friend std::ostream& operator<<(std::ostream& os, const BinaryTree<T>& bt)
    {
        os << print(bt.root) << "\n";
        return os;
    }

    bool search(T val)
    {
        Node<T>* currNode = root;
        while (currNode)
        {
            if (currNode->val == val)
                return true;
            else if (currNode->val < val)
                currNode = currNode->rightNode;
            else
                currNode = currNode->leftNode;
        }
        return false;
    }
};

template <typename T>
void insert_element(BinaryTree<T>& root)
{
    std::cout << "Enter value to insert: ";
    T value {};
    std::cin >> value;

    root.insert(value);
    std::cout << "Successfully inserted " << value << "!\n\n";
}

template <typename T>
void search_element(BinaryTree<T>& root)
{
    std::cout << "Enter value to insert: ";
    T value {};
    std::cin >> value;

    if (root.search(value))
        std::cout << "Value exists in tree.\n\n";
    else
        std::cout <<  "Value does not exist in tree.\n\n";
}

int main()
{
    BinaryTree<dType> root{};

    do
    {
        try
        {
            std::cout << "What would you like to do?\n";
            std::cout << "1. Insert an element\n";
            std::cout << "2. Get height of tree\n";
            std::cout << "3. Print the tree\n";
            std::cout << "4. Search for an element in the tree\n";
            std::cout << "5. Quit\n";
            std::cout << "Enter your choice.\n";

            int ch {};
            std::cin >> ch;

            switch (ch)
            {
                case 1: insert_element(root);
                        break;
                case 2: std::cout << "Height is " << root.height() << ".\n\n";
                        break;
                case 3: std::cout << "Tree is:\n" << root << "\n";
                        break;
                case 4: search_element(root);
                        break;
                case 5: return 0;
                default: std::cout << "Invalid option. Try again.\n\n";
            }
        }
        catch (std::runtime_error e)
        {
            std::cerr << e.what() << "\n\n";
        }
    }
    while(true);


    return 0;
}
