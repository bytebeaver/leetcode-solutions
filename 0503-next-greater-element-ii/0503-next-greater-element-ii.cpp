class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();

        stack<int> st;              // monotonic decreasing stack (stores VALUES, not indices)
        vector<int> nge(n);         // final answer array, size n (only original indices matter)

        // Traverse from 2n-1 down to 0 -> this simulates a "doubled" array (nums+nums)
        // WITHOUT actually creating a new array, using idx = i % n to map back
        for(int i = 2*n - 1; i>=0; i--)
        {
            // Remove all elements from stack that are <= current element,
            // because they can never be the "next greater" for anything after this point --
            // current element is a better (nearer + bigger-or-equal) candidate for future indices
            while(!st.empty() && st.top() <= nums[i%n])
            st.pop();

            // Only record the answer during the "real" pass (i < n),
            // by this point the stack already contains circular "future" elements
            // thanks to the warm-up pass (i from 2n-1 to n) that ran first
            if(i<n)
            {
                nge[i] = (st.empty())?-1:st.top();   // top of stack = next greater element, empty = -1
            }

            // Push current element so it becomes a candidate "next greater" for elements to its left
            st.push(nums[i%n]);
        }

    return nge;
    }
};