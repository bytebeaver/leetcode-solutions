class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        
        int i=0;

        int n = heights.size();

        vector<int> ans(n,0);
        stack<int> st;


        while( i<n)
        {
            while( !st.empty() && heights[st.top()] < heights[i])
            {
                ans[ st.top() ]++;
                st.pop();
            }

            if( st.empty())
            {
                st.push(i);
                i++;
            }

            else if( heights[i] < heights[st.top()])
            {
                ans[ st.top() ]++;
                st.push(i);
                i++;
            }
        }

        return ans;
    }
};