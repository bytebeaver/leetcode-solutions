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
    int diameter = INT_MIN;

    
    
    int Diameter(TreeNode* root) {
        
        if(!root) return 0;

        int left_height = Diameter(root->left);
        int right_height = Diameter(root->right);

        diameter = max(diameter , left_height+right_height);

        return 1 + max(left_height, right_height);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        
      Diameter(root);

      return diameter;

    }
};