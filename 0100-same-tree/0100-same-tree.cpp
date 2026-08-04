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
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
        
//         if(!p || !q) return p==q;

//         if(p->val != q->val) return false;

//         bool v1=isSameTree(p->left, q->left);
//         bool v2=isSameTree(p->right, q->right);

//         return v1 && v2;
//     }
// };


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(!p || !q) return p==q;

        return (p->val == q->val) && isSameTree(p->left, q->left) &&isSameTree(p->right, q->right);
    }
};