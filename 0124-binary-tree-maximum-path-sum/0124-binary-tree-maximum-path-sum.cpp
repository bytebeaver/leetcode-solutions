class Solution {
public:
    int result = INT_MIN;  // global: overall max path sum

    int pathSum_Maxi(TreeNode *root)
    {
        if(!root) return 0;  // base case: null node contributes 0

        // clamp negative contributions to 0 (don't carry a loss)
        int left_subtree_path_sum = max(0, pathSum_Maxi(root->left));
        int right_subtree_path_sum = max(0, pathSum_Maxi(root->right));

        // path that goes through this node using BOTH sides (final path candidate)
        int pathsum = left_subtree_path_sum + right_subtree_path_sum + root->val;

        result = max(result, pathsum);  // update global answer

        // return best single-side contribution to send upward to parent
        return max(left_subtree_path_sum, right_subtree_path_sum) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        pathSum_Maxi(root);
        return result;
    }
};