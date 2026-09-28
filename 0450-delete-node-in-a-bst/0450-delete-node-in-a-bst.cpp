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

    // Function to find the smallest node
    // in a subtree
    TreeNode* findMin(TreeNode* root)
    {
        while(root->left != NULL)
            root = root->left;

        return root;
    }


    TreeNode* deleteNode(TreeNode* root, int key)
    {
        // If tree is empty OR key is not found
        if(root == NULL)
            return root;


        // Key is smaller → search in left subtree
        if(key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }


        // Key is greater → search in right subtree
        else if(key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }


        // We found the node to delete
        else
        {
            // CASE 1:
            // Node has NO children
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }


            // CASE 2:
            // Node has ONLY right child
            else if(root->left == NULL)
            {
                TreeNode* temp = root->right;

                delete root;

                return temp;
            }


            // CASE 2:
            // Node has ONLY left child
            else if(root->right == NULL)
            {
                TreeNode* temp = root->left;

                delete root;

                return temp;
            }


            // CASE 3:
            // Node has BOTH left and right children
            else
            {
                // Find inorder successor
                // = smallest node in right subtree
                TreeNode* successor = findMin(root->right);

                // Copy successor's value into current node
                root->val = successor->val;

                // Delete the duplicate successor node
                root->right = deleteNode(root->right, successor->val);
            }
        }

        // Return root of the modified subtree
        return root;
    }
};