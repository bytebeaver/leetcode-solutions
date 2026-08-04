/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode *, bool> mp;

     int find_p_andtracepathinmap(TreeNode *root, TreeNode *p)
     {
        if(!root) return 0;

        if(root == p)
        {
            mp[p] =1;
            return 1 ;
        }


        int v1=find_p_andtracepathinmap(root->left, p);
        if(v1 ==1)
        {
            mp[root]=1;
            return 1;
        }

        int v2=find_p_andtracepathinmap(root->right, p);
        if(v2 ==1)
        {
            mp[root]=1;
            return 1;
        }


    return 0;


     }

    pair<TreeNode*, bool> function_for_q(TreeNode *root, TreeNode *q)
{
    if(root == nullptr)
        return {nullptr, false};

    if(root == q)
    {
        if(mp.count(root))
            return {root, true};   // q itself is LCA

        return {root, false};      // start backtracking
    }

    auto left = function_for_q(root->left, q);

    if(left.first)
    {
        if(left.second)
            return left;           // LCA already found

        if(mp.count(root))
            return {root, true};   // Current node becomes LCA

        return {root, false};      // Continue backtracking
    }

    auto right = function_for_q(root->right, q);

    if(right.first)
    {
        if(right.second)
            return right;

        if(mp.count(root))
            return {root, true};

        return {root, false};
    }

    return {nullptr, false};
}
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        find_p_andtracepathinmap(root,p);
        TreeNode *temp = function_for_q(root,q).first;

        return temp;


        
    }
};