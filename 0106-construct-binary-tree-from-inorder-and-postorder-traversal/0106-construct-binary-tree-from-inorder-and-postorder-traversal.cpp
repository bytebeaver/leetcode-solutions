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
    unordered_map<int, int> mp; // value -> inorder index (fast lookup)

    TreeNode* BuildTree(vector<int> &postorder, int post_start, int post_end,
                         vector<int> &inorder, int inorder_start, int inorder_end)
    {
        // base case: empty range means empty subtree
        if (post_start > post_end || inorder_start > inorder_end)
            return nullptr;

        // postorder's last element is always the root
        TreeNode* root = new TreeNode(postorder[post_end]);

        // find root's position in inorder array
        int idx_root = mp[root->val];

        // number of nodes in left subtree
        int left_size = idx_root - inorder_start;

        // build left subtree using left part of postorder & inorder
        root->left = BuildTree(postorder, post_start, post_start + left_size - 1,
                                inorder, inorder_start, idx_root - 1);

        // build right subtree using right part of postorder & inorder
        root->right = BuildTree(postorder, post_start + left_size, post_end - 1,
                                 inorder, idx_root + 1, inorder_end);

        return root; // return current subtree's root
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // pre-fill map: value -> its index in inorder
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        // call helper with full range of both arrays
        return BuildTree(postorder, 0, postorder.size() - 1,
                          inorder, 0, inorder.size() - 1);
    }
};