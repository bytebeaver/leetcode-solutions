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
    int result = INT_MIN;

    int pathSum_Maxi(TreeNode *root)
    {
        
        if(!root) return 0;

        int left_subtree_path_sum = max(0,pathSum_Maxi(root->left));
        int right_subtree_path_sum = max (0,pathSum_Maxi(root->right));

        int pathsum = left_subtree_path_sum + right_subtree_path_sum + root->val;

        result = max(result, pathsum);

        return max(left_subtree_path_sum, right_subtree_path_sum) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        
        if(!root) return 0;
        
        pathSum_Maxi(root);
        
        return result;

    }
};