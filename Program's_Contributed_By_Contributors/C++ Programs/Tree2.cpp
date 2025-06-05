#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter the rootData" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the number Of children " << front->data << endl;
        int numChildren;
        cin >> numChildren;
        for (int i = 0; i < numChildren; i++)
        {
            int childData;
            cout << "Enter the chilData of the " << i + 1 << " child of " << front->data
                 << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << endl;
    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " ";
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int numNodes(TreeNode<int> *root)
{
    int ans = 1;
    if (root == NULL)
    {
        return 0;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = ans + numNodes((root->children[i]));
    }
    return ans;
}
void printLevelK(TreeNode<int> *root, int level)
{
    if (level == 0)
    {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printLevelK(root->children[i], level - 1);
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    int noOfNodes = numNodes(root);
    cout << noOfNodes << endl;
    int level;
    cout << "Enter the level upto which you wanna print" << endl;
    cin >> level;
    printLevelK(root, level);
    return 0;
}
