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
// ============================================================
// APPROACH 1: RECURSIVE PREORDER TRAVERSAL
// ============================================================
// ALGORITHM (in plain words):
// Preorder means: Visit Root -> Traverse Left -> Traverse Right
// 1. If the current node is NULL, do nothing (base case, stops recursion)
// 2. Otherwise:
//    a) Process/visit the current node first (add its value to answer)
//    b) Recursively traverse the entire left subtree
//    c) Recursively traverse the entire right subtree
// Since we use the class-level "ans" vector, every recursive call
// keeps adding to the SAME vector (no need to merge results manually)
// ============================================================

// class Solution {
// public:
//     vector<int> ans; // class member vector - shared across all recursive calls
//                       // so we don't need to merge/return sub-results manually

//     vector<int> preorderTraversal(TreeNode* root) {

//         if(root) // base case check: only proceed if node exists (not NULL)
//         {
//             ans.push_back(root->val);       // STEP 1: visit root -> record its value FIRST (this is what makes it "pre"-order)
//             preorderTraversal(root->left);  // STEP 2: recursively go into the left subtree completely
//             preorderTraversal(root->right); // STEP 3: recursively go into the right subtree completely
//         }
//         // if root is NULL, we simply skip the above block and fall through to return
//         // this acts as the implicit base case that stops infinite recursion

//         return ans; // return the accumulated result
//                      // (on the outermost call, this returns the final complete answer)
//     }
// };


// ============================================================
// APPROACH 2: ITERATIVE PREORDER TRAVERSAL (using explicit stack)
// ============================================================
// ALGORITHM (in plain words):
// We simulate recursion manually using a stack, since recursion itself
// uses a call stack internally.
// Idea: 
// 1. Keep going LEFT as far as possible, visiting (recording) each node
//    as soon as we reach it (because preorder visits root before children).
// 2. Every time we move left and there EXISTS a right child, push that
//    right child onto the stack so we don't lose track of it — we'll need
//    to come back and process it later.
// 3. When we can't go left anymore (root becomes NULL), pop the last saved
//    right child from the stack and repeat the same process from there.
// 4. Stop when there are no more nodes to process (root is NULL AND stack is empty)
// ============================================================

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;        // local vector to store the final traversal order
        stack<TreeNode*> st;    // stack to temporarily hold "pending" right children

        // loop continues as long as either:
        // - there's a current node to process (root != NULL), OR
        // - there are pending right subtrees saved in the stack
        while(root || !st.empty())

            if(root) // CASE 1: we have a valid current node to process
            {
                ans.push_back(root->val); 
                // visit the node immediately (preorder = visit before children)

                if(root->right)
                    st.push(root->right); 
                // if a right child exists, save it on the stack for later
                // (we must finish the left side first, so we "park" it here)

                root = root->left; 
                // move to the left child and continue the same process
                // this keeps drilling down the left spine of the tree
            }

            else // CASE 2: root became NULL, meaning we've hit a dead end going left
            {
                root = st.top(); 
                // fetch the most recently saved right child from the stack
                // (this resumes traversal from the nearest unfinished branch)

                st.pop(); 
                // remove it from the stack since we're about to process it now
            }

        return ans; // once both root is NULL and stack is empty, traversal is complete
    }
};