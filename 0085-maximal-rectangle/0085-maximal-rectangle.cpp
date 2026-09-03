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


int maximalRectangle(vector<vector<char>>& matrix) {
    
    // Number of rows in the matrix
    int n = matrix.size();

    // Number of columns in the matrix
    int m = matrix[0].size();

    // Stores the maximum rectangle area found so far
    int max_area = 0;

    // prefix_sum[i][j] = number of consecutive 1s
    // ending at row i in column j
    //
    // Initially, all values are 0
    vector<vector<int>> prefix_sum(n, vector<int>(m, 0));


    // ---------------------------------------------------------
    // STEP 1: Build the height of consecutive 1s for each cell
    // ---------------------------------------------------------

    // Traverse column by column
    for (int j = 0; j < m; j++)
    {
        // Keeps track of consecutive 1s in the current column
        int sum = 0;

        // Traverse from top to bottom in the current column
        for (int i = 0; i < n; i++)
        {
            // Convert character ('0' or '1') into integer
            // and add it to the current consecutive count
            sum += matrix[i][j] - '0';

            // If the current cell is 0,
            // consecutive 1s are broken.
            // Therefore, reset the count to 0.
            if (matrix[i][j] == '0')
                sum = 0;

            // Store the height of consecutive 1s
            // ending at (i, j)
            prefix_sum[i][j] = sum;
        }
    }


    // ---------------------------------------------------------
    // STEP 2: Treat every row as a histogram
    // ---------------------------------------------------------

    // Each row of prefix_sum represents a histogram.
    //
    // For every row, find the largest rectangle
    // that can be formed using its heights.
    for (int i = 0; i < n; i++)
    {
        // largestRectangleArea() finds the maximum
        // rectangular area in this histogram.
        //
        // Take the maximum over all rows.
        max_area = max(
            max_area,
            largestRectangleArea(prefix_sum[i])
        );
    }


    // Return the largest rectangle of 1s
    // found anywhere in the matrix.
    return max_area;
}
};