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
    // Morris Inorder Traversal — O(1) extra space, no stack/recursion needed.
    // Idea: temporarily create a "thread" (fake link) from the rightmost node
    // of the left subtree back to the current node, so that once we finish
    // the left subtree we can automatically come back up to current
    // without needing a stack.
    vector<int> inorderTraversal(TreeNode* root) {
        
        TreeNode *curr = root;      // pointer walking through the tree
        vector<int> inorder;        // stores final inorder result

        while (curr) {

            if (curr->left != nullptr) {
                // Left subtree exists, so find its INORDER PREDECESSOR
                // (rightmost node of left subtree) — this is the node
                // that should be visited just before "curr"
                TreeNode* predecessor = curr->left;

                while (predecessor->right != nullptr)
                    predecessor = predecessor->right;

                // create a temporary thread: predecessor -> curr
                // this lets us "return" to curr after finishing left subtree
                predecessor->right = curr;
            }

            if (curr->left != nullptr) {
                // move into left subtree (thread is already set up above)
                TreeNode* leftChild = curr->left;

                curr->left = nullptr;   // cut original left link (mark as visited/processed)
                curr = leftChild;       // move left
            }
            else {
                // no left subtree left to explore ->
                // either it's a true leaf-ish node, OR we just arrived here
                // via the thread created earlier (predecessor->right = curr)
                inorder.push_back(curr->val);  // visit current node
                curr = curr->right;            // move right (real right child OR thread back up)
            }
        }

        return inorder;
    }
};