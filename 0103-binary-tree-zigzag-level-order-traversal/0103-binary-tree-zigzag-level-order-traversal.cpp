/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        list<TreeNode*> l;              // deque-like structure (double ended)
        vector<vector<int>> zigzag;     // final result
        int turn = 0;                   // 0 = left->right, 1 = right->left

        if (!root) return zigzag;       // empty tree edge case
        l.push_back(root);

        while (!l.empty()) {
            int size = l.size();        // number of nodes in current level
            vector<int> level;

            if (turn == 0) {
                // process left to right: pop front, push children at back
                for (int i = 0; i < size; i++) {
                    TreeNode* n = l.front();
                    l.pop_front();
                    level.push_back(n->val);
                    if (n->left)  l.push_back(n->left);
                    if (n->right) l.push_back(n->right);
                }
                zigzag.push_back(level);
                turn = 1;                // flip direction for next level
            }
            else {
                // process right to left: pop back, push children at front (right then left)
                for (int i = 0; i < size; i++) {
                    TreeNode* n = l.back();
                    l.pop_back();
                    level.push_back(n->val);
                    if (n->right) l.push_front(n->right);
                    if (n->left)  l.push_front(n->left);
                }
                zigzag.push_back(level);
                turn = 0;                // flip direction back
            }
        }

        return zigzag;
    }
};