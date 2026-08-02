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

    int Depth(TreeNode* root, int depth)
    {
        if(!root) return depth-1;

        depth = max( 1 + Depth(root->left, depth) , 1 + Depth(root->right, depth) ) ;
        
        return depth;
    }
    int maxDepth(TreeNode* root) {
        
        if(!root) return 0;

        int depth = 1;
        return Depth(root, depth);


    }
};