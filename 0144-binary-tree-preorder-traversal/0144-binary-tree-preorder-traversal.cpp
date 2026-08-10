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
        while(current)
        {
            if(current->left == nullptr)
            {
                preorder.push_back(current->val);
                current= current->right;
            }
            else if(current->left != nullptr)
            {
                TreeNode *leftchild = current->left;

                while(leftchild -> right != nullptr && leftchild->right != current)
                leftchild = leftchild->right;

                if(leftchild->right == nullptr)
                {
                    leftchild->right = current;
                    preorder.push_back(current->val);
                    current = current->left;
                }

                if(leftchild ->right == current)
                {
                    leftchild ->right = nullptr;
                    current =  current->right;
                }
            }

        }

        return preorder;
    }
};