class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();

        stack<int> st;

        int max_area = 0;

        for(int i=0; i<n ; i++)
        {
            while( !st.empty() && heights[st.top()] > heights[i])
            {
                int element = st.top();
                st.pop();
                int nse_idx = i;
                int pse_idx = (st.empty())? -1 : st.top();

                int area = heights[element] * ( nse_idx - pse_idx -1 );
                max_area = max(max_area, area);
            }

            st.push(i);
        }

        while(!st.empty())
        {
            int element = st.top();
            st.pop();
            int nse_idx = n;
            int pse_idx = (st.empty())? -1:st.top();

            int area =  heights[element] * ( nse_idx - pse_idx -1 );
            max_area = max(max_area, area);
            
        }

        return max_area;
    }
};