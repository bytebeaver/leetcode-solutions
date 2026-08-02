class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        // final answer: har level ki values ek alag vector mein
        vector<vector<int>> ans;

        // base case: tree hi empty hai, koi traversal nahi karni
        if (!root) return ans;

        // BFS ke liye queue banaya, isme TreeNode pointers store honge
        queue<TreeNode*> q;

        // root ko queue mein daal diya, traversal yahin se start hogi
        q.push(root);

        // jab tak queue mein nodes hain, matlab process karne ke liye levels baaki hain
        while (!q.empty()) {

            // current level ki values yahan store hongi
            vector<int> level;

            // IMPORTANT: size yahin capture kar liya, loop ke andar nahi
            // ye batata hai ki queue mein abhi sirf CURRENT level ke nodes hain
            // agar ye na karte to loop ke andar push hone wale next-level nodes
            // bhi isi level mein mix ho jaate
            int size = q.size();

            // sirf current level ke 'size' nodes hi process karo
            for (int i = 0; i < size; i++) {

                // queue ke front se node nikala (FIFO order maintain hota hai)
                TreeNode* node = q.front();

                // nikalne ke baad usse queue se remove kar diya
                q.pop();

                // agar left child exist karta hai, use next level ke liye
                // queue ke end mein daal do (abhi process nahi hoga)
                if (node->left)  q.push(node->left);

                // same logic right child ke liye
                if (node->right) q.push(node->right);

                // current node ki value ko is level ki list mein add kar diya
                level.push_back(node->val);
            }

            // current level poora process ho gaya, ise final answer mein daal do
            ans.push_back(level);

            // loop wapas condition check karega:
            // agar queue mein next level ke nodes hain to phir se chalega
        }

        // saare levels process ho gaye, final result return karo
        return ans;
    }
};