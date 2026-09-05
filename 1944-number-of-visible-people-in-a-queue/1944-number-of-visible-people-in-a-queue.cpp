class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {

        int n = heights.size();

        vector<int> ans(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            // Current person can see all shorter people
            // that are removed from the stack.
            while (!st.empty() && heights[st.top()] < heights[i]) {
                ans[st.top()]++;
                st.pop();
            }

            // If someone taller is still in the stack,
            // the current person can see that taller person.
            if (!st.empty()) {
                ans[st.top()]++;
            }

            // Current person becomes a candidate for
            // future people to see.
            st.push(i);
        }

        return ans;
    }
};