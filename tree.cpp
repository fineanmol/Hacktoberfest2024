
#include <bits/stdc++.h>

void markParents(BinaryTreeNode<int> *root, unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &parent_track, BinaryTreeNode<int> *target)
{
    queue<BinaryTreeNode<int> *> queue;
    queue.push(root);
    while (!queue.empty())
    {
        BinaryTreeNode<int> *current = queue.front();
        queue.pop();
        if (current->left)
        {
            parent_track[current->left] = current;
            queue.push(current->left);
        }
        if (current->right)
        {
            parent_track[current->right] = current;
            queue.push(current->right);
        }
    }
}

vector<BinaryTreeNode<int> *> printNodesAtDistanceK(BinaryTreeNode<int> *root, BinaryTreeNode<int> *target, int k)
{
    unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> parent_track;

    markParents(root, parent_track, target);

    unordered_map<BinaryTreeNode<int> *, bool> visited;

    queue<BinaryTreeNode<int> *> queue;
    queue.push(target);
    visited[target] = true;
    int curr_level = 0;

    while (!queue.empty())
    {
        int size = queue.size();

        if (curr_level++ == k)
            break;

        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *current = queue.front();
            queue.pop();
            if (current->left && !visited[current->left])
            {
                queue.push(current->left);
                visited[current->left] = true;
            }
            if (current->right && !visited[current->right])
            {
                queue.push(current->right);
                visited[current->right] = true;
            }
            if (parent_track[current] && !visited[parent_track[current]])
            {
                queue.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    vector<BinaryTreeNode<int> *> result;
    while (!queue.empty())
    {
        BinaryTreeNode<int> *current = queue.front();
        queue.pop();
        result.push_back(current);
    }
    return result;
}
