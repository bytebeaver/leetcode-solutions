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
    map <int, int> mp;


    TreeNode *BuildTree( vector<int> preorder,int  pre_start, int pre_end, vector<int> inorder, int inorder_start , int inorder_end )
    {
        if(pre_start > pre_end || inorder_start > inorder_end)
        return nullptr;

        TreeNode *root = new TreeNode (preorder[pre_start]);

        int index_of_root_in_inorder = mp[root->val];

        int number_of_nums_to_the_left_of_root_in_inorder = index_of_root_in_inorder - inorder_start;

        root->left = BuildTree(preorder, pre_start + 1, pre_start + number_of_nums_to_the_left_of_root_in_inorder  , inorder ,   
         inorder_start, index_of_root_in_inorder - 1);      

          root->right = BuildTree(preorder, pre_start + number_of_nums_to_the_left_of_root_in_inorder + 1 , pre_end  , inorder ,   
         index_of_root_in_inorder + 1, inorder_end);


         return root;                               
    }




    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0; i<inorder.size(); i++)
        {
            mp[ inorder[i] ] =i;
        }
        
        int pre_start = 0;
        int pre_end = preorder.size() -1;

        int inorder_start = 0;
        int inorder_end = inorder.size()-1;

        return  BuildTree(preorder , pre_start, pre_end, inorder, inorder_start, inorder_end);


    }
};