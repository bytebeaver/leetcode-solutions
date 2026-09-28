class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // If tree is empty, new node becomes the root
        if(root == NULL) return new TreeNode(val);

        // Keep a pointer to traverse the tree
        TreeNode *cur = root;

        while(true)
        {
            // val >= cur->val → go to right
            // This allows duplicate values on the right
            if(cur->val <= val)
            {
                // If right child exists, keep moving right
                if(cur->right != NULL)
                    cur = cur->right;

                // Otherwise insert new node here
                else
                {
                    cur->right = new TreeNode(val);
                    break;
                }
            }

            // val < cur->val → go to left
            else
            {
                // If left child exists, keep moving left
                if(cur->left != NULL)
                    cur = cur->left;

                // Otherwise insert new node here
                else
                {
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }

        // Return original root
        return root;
    }
};