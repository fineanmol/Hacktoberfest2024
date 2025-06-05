class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        unordered_map<TreeNode*, bool> evaluated;

        while (!st.empty()) {
            TreeNode* topNode = st.top();

            // If the node is a leaf node, store its value in the evaluated
            // hashmap and continue
            if (!topNode->left and !topNode->right) {
                st.pop();
                evaluated[topNode] = topNode->val;
                continue;
            }

            // If both the children have already been evaluated, use their
            // values to evaluate the current node.
            if (evaluated.find(topNode->left) != evaluated.end() and
                evaluated.find(topNode->right) != evaluated.end()) {
                st.pop();
                if (topNode->val == 2) {
                    evaluated[topNode] =
                        evaluated[topNode->left] || evaluated[topNode->right];
                } else {
                    evaluated[topNode] =
                        evaluated[topNode->left] && evaluated[topNode->right];
                }
            } else {
                // If both the children are not leaf nodes, push the current
                // node along with its left and right child back into the stack.
                st.push(topNode->right);
                st.push(topNode->left);
            }
        }

        return evaluated[root] == 1;
    }
};