class StockSpanner {
public:

    // Member variable:
    // Stores the index of the current stock price.
    // It belongs to the object, so its value persists
    // across multiple calls to next().
    int index;

    // Member variable:
    // Stack stores pairs of:
    // {stock price, index}
    //
    // It is maintained as a monotonic decreasing stack.
    // The top of the stack represents the nearest
    // previous greater price.
    stack<pair<int, int>> st;


    // Constructor
    // Automatically called when a StockSpanner object is created.
    StockSpanner()
    {
        // Initialize the index before processing any price.
        // First call to next() will increment it to 0.
        index = -1;
    }


    // Member function.
    // Called every time we receive a new stock price.
    //
    // price = current day's stock price
    // Returns the span of the current price.
    int next(int price)
    {
        // Move to the next index.
        // Initially index = -1, so first call makes index = 0.
        index += 1;


        // Variable to store the answer for this call.
        int ans;


        // Remove all previous prices that are
        // less than or equal to the current price.
        //
        // Why?
        // They can never be the previous greater element
        // for the current price.
        while (!st.empty() && st.top().first <= price)
        {
            // Remove the top element because its price
            // is smaller than or equal to the current price.
            st.pop();
        }


        // If the stack is empty:
        // There is no previous greater price.
        //
        // We use -1 as the imaginary index of
        // the previous greater element.
        //
        // Span = current index - (-1)
        //      = index + 1
        //
        // Otherwise:
        // st.top().second contains the index of the
        // nearest previous greater price.
        //
        // Span = current index - previous greater index.
        ans = index - (st.empty() ? -1 : st.top().second);


        // Store the current price and its index
        // in the stack.
        //
        // It may become the previous greater element
        // for a future stock price.
        st.push({price, index});


        // Return the span calculated for the current price.
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */