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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        list<TreeNode *> l;
        
        vector<vector<int>> zigzag;
        int turn =0;

        if(!root) return zigzag;
        l.push_back(root);

        while(!l.empty())
        {
            int size = l.size();
            vector<int> level;
            if(turn == 0)
            {
                //front se pop krenge and back se push krenge
                for(int i=0 ; i<size; i++)
                {
                     TreeNode * n = l.front();
                     l.pop_front();
                     level.push_back(n->val);
                     if(n->left) l.push_back(n->left);
                     if(n->right) l.push_back(n->right);
                }

                zigzag.push_back(level);
                turn =1;
            }


            else if(turn == 1)
            {
                //back se pop krenge and front se push krenge pehle right child fir left child
                for(int i=0 ; i<size; i++)
                {
                     TreeNode * n = l.back();
                     l.pop_back();
                     level.push_back(n->val);
                     if(n->right) l.push_front(n->right);
                     if(n->left) l.push_front(n->left);
                }

                zigzag.push_back(level);
                turn =0;
            }
        }

    return zigzag;
    }
};