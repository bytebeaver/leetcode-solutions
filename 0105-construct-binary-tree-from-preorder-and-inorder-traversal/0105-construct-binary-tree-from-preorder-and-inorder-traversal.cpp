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
    map<int,int> mp; // value -> index in inorder, for O(1) root lookup

    TreeNode* BuildTree(vector<int>& preorder, int pre_start, int pre_end,
                         vector<int>& inorder, int inorder_start, int inorder_end) {

        // base case: no elements left in this range
        if (pre_start > pre_end || inorder_start > inorder_end)
            return nullptr;

        // preorder's first element in this range = root of this subtree
        TreeNode* root = new TreeNode(preorder[pre_start]);

        // find root's position in inorder using map (O(1))
        int rootIdx = mp[root->val];

        // elements to left of root in inorder = size of left subtree
        int leftSize = rootIdx - inorder_start;

        // build left subtree: preorder shifts by 1, inorder is left of rootIdx
        root->left = BuildTree(preorder, pre_start + 1, pre_start + leftSize,
                                inorder, inorder_start, rootIdx - 1);

        // build right subtree: preorder starts after left part, inorder is right of rootIdx
        root->right = BuildTree(preorder, pre_start + leftSize + 1, pre_end,
                                 inorder, rootIdx + 1, inorder_end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // precompute value->index map for O(1) root lookup
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return BuildTree(preorder, 0, preorder.size()-1,
                          inorder, 0, inorder.size()-1);
    }
};