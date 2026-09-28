class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // If tree is empty, new node becomes the root
        if (root == NULL)
            return new TreeNode(val);

        TreeNode* returningNode = root;

        // Create the new node
        TreeNode* newNode = new TreeNode(val);

        while (true)
        {
            // Go to the right subtree
            if (root->val < val)
            {
                // If right is empty, insert here
                if (root->right == NULL)
                {
                    root->right = newNode;
                    break;
                }

                root = root->right;
            }

            // Go to the left subtree
            else
            {
                // If left is empty, insert here
                if (root->left == NULL)
                {
                    root->left = newNode;
                    break;
                }

                root = root->left;
            }
        }

        return returningNode;
    }
};