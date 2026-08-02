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
    // Ye function height return karta hai normally,
    // lekin agar kahin bhi tree unbalanced mile to -1 return karega (signal value)
    int balanceCheck(TreeNode* root)
    {
        // base case: empty subtree ki height 0 hoti hai
        // (ye height calculation hai, isliye 0 return kiya, boolean nahi)
        if (!root) return 0;

        // left subtree ki height nikaalo
        int lh = balanceCheck(root->left);
        // agar left subtree mein already unbalance mil chuka hai,
        // to aage kuch calculate karne ki zaroorat nahi, seedha -1 bubble up karo
        if (lh == -1) return -1;

        // right subtree ki height nikaalo
        int rh = balanceCheck(root->right);
        // same logic: agar right subtree unbalanced hai to turant -1 return karo
        if (rh == -1) return -1;

        // ab current node ka check: left aur right height ka diff 1 se zyada?
        // agar haan, to is node par tree unbalanced hai
        if (abs(lh - rh) > 1) return -1;

        // sab sahi hai, current node ki height return karo
        // (bade subtree ki height + khud ka 1 level)
        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        
        // empty tree hamesha balanced hota hai
        if (!root) return true;

        // agar balanceCheck kahin bhi -1 return na kare,
        // matlab poora tree balanced hai
        return balanceCheck(root) != -1;
    }
};