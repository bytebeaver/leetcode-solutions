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

 //MORRIS TRAVERSAL ---- Thread the Tree
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode *current = root;
        vector<int> preorder;

        while (current) { // jab tak current null na ho
            
            if (current->left == nullptr) { 
                // no left subtree -> push karo aur right pe chale jao
                preorder.push_back(current->val);
                current = current->right;
            } 
            else {
                // left subtree exist karta hai, predecessor dhoondo
                TreeNode *leftchild = current->left;

                // rightmost node of left subtree tak jao (ya thread mil jaaye)
                while (leftchild->right != nullptr && leftchild->right != current)
                    leftchild = leftchild->right;

                if (leftchild->right == nullptr) { 
                    // thread nahi bani -> banao aur PREORDER mein push karo abhi
                    leftchild->right = current;
                    preorder.push_back(current->val); // preorder ki key trick
                    current = current->left; // left explore karo
                } 
                else { 
                    // thread already bani -> left fully visited, ab unthread karo
                    leftchild->right = nullptr;
                    current = current->right; // right subtree pe jao
                }
            }
        }

        return preorder;
    }
};