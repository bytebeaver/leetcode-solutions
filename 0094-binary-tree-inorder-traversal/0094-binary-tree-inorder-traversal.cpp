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
vector<int> inorderTraversal(TreeNode* root) {
    TreeNode *curr = root;
    vector<int> inorder;

    while (curr) {

        if (curr->left == nullptr) {
            // Left subtree nahi hai -> seedha visit karo aur right pe chale jao
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        else {
            // Left subtree hai -> predecessor (rightmost node) dhoondo
            TreeNode* predecessor = curr->left;

            //  dono conditions check ho rahi hain
            while (predecessor->right != nullptr && predecessor->right != curr)
                predecessor = predecessor->right;

            if (predecessor->right == nullptr) {
                // PEHLI BAAR is subtree pe aaye ho -> thread banao, left mein jao
                predecessor->right = curr;
                curr = curr->left;
            }
            else {
                // DOOSRI BAAR aaye ho (thread se wapas) -> thread HATAO (restore!), visit karo
                predecessor->right = nullptr;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return inorder;
}
};