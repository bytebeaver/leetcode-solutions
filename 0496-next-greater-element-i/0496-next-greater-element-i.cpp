class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();

        // mp stores: element -> its next greater element (or -1 if none)
        map<int, int> mp;

        // Monotonic DECREASING stack (bottom -> top: large -> small)
        // Represents "candidates" that could still be someone's next-greater
        stack<int> st;

        // Traverse nums2 from RIGHT to LEFT
        for(int i = n2-1; i>=0; i--)
        {
            // Pop all elements from stack that are <= current element,
            // because they can never be the "next greater" for any element
            // further to the left (nums2[i] itself is a better/closer candidate)
            while(!st.empty() && st.top() <= nums2[i])
                st.pop();

            // If stack empty after popping -> no greater element exists to the right
            if(st.empty())
                mp[nums2[i]] = -1;
            else
                // top of stack is the nearest greater element (since stack is decreasing)
                mp[nums2[i]] = st.top();

            // Push current element so it can act as a candidate for elements to its left
            st.push(nums2[i]);
        }

        // Now simply answer each query in nums1 using the precomputed map
        vector<int> result;
        for(int i=0; i<n1; i++)
        {
           result.push_back( mp[nums1[i]] );
        }

        return result;
    }
};