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
    unordered_map<int, int> mp;
    
    TreeNode* BuildTree(vector<int> &postorder, int post_start, int post_end, vector<int> &inorder, int inorder_start, int inorder_end)
    {
        if(post_start>post_end || inorder_start > inorder_end)
        return nullptr;

        TreeNode* root = new TreeNode(postorder[post_end]);

        int idx_root = mp[root->val];

        int left_size = idx_root - inorder_start;

        root->left = BuildTree(postorder, post_start, post_start + left_size -1, inorder, inorder_start , idx_root -1);

        root->right = BuildTree(postorder, post_start + left_size , post_end -1 , inorder, idx_root +1 , inorder_end);


        return root;

    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        for(int i=0; i<inorder.size(); i++)
        mp[inorder[i] ] = i;

        int post_start = 0;
        int post_end = postorder.size()-1;


        int inorder_start = 0;
        int inorder_end = inorder.size()-1;

        return BuildTree(postorder, post_start, post_end, inorder, inorder_start , inorder_end);
    }
};