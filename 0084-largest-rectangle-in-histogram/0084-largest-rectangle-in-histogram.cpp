class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        // Number of bars in the histogram
        int n = heights.size();

        // Stack stores INDICES of bars.
        // We maintain the stack such that the heights
        // corresponding to these indices are in increasing order.
        stack<int> st;

        // Stores the maximum rectangle area found so far
        int max_area = 0;

        // Traverse every bar from left to right
        for(int i = 0; i < n; i++)
        {
            // If current bar is smaller than the bar at the
            // top of the stack, then the current bar is the
            // Next Smaller Element (NSE) for the top bar.
            //
            // IMPORTANT:
            // st.top() is an INDEX, so we use heights[st.top()]
            // to get the actual height.
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                // Index of the bar whose rectangle we are calculating
                int element = st.top();
                st.pop();

                // Current index i is the Next Smaller Element
                // for 'element'
                int nse_idx = i;

                // After popping 'element', the new stack top
                // is the Previous Smaller Element (PSE).
                //
                // If stack is empty, there is no smaller element
                // on the left, so we use -1.
                int pse_idx = (st.empty()) ? -1 : st.top();

                // Width of the largest rectangle using
                // heights[element] as the minimum height:
                //
                //        nse_idx - pse_idx - 1
                //
                // Height = heights[element]
                // Width  = number of bars between PSE and NSE
                int area = heights[element] * (nse_idx - pse_idx - 1);

                // Update maximum area
                max_area = max(max_area, area);
            }

            // Store the current bar's INDEX in the stack
            st.push(i);
        }

        // Some bars may still remain in the stack.
        // For these bars, there is no smaller element to their right.
        // Therefore, their NSE is considered to be n.
        while(!st.empty())
        {
            // Index of the bar whose rectangle we are calculating
            int element = st.top();
            st.pop();

            // No smaller element exists to the right,
            // so the right boundary is outside the array.
            int nse_idx = n;

            // After popping 'element', the new stack top
            // becomes its Previous Smaller Element.
            //
            // If stack is empty, there is no smaller element
            // on the left, so PSE = -1.
            int pse_idx = (st.empty()) ? -1 : st.top();

            // Calculate rectangle area:
            //
            // Height = heights[element]
            // Width  = nse_idx - pse_idx - 1
            int area = heights[element] * (nse_idx - pse_idx - 1);

            // Update maximum area
            max_area = max(max_area, area);
        }

        // Return the largest rectangle area
        return max_area;
    }
};