class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        // If we cannot make any profitable transaction,
        // the answer will remain 0.
        int max_profit = 0;

        // i keeps track of the index having the
        // minimum buying price seen so far.
        int i = 0;

        // j represents the current selling day.
        // We start from day 1 because buying and selling
        // must happen on different days.
        for (int j = 1; j < n; j++) {

            // Consider buying on day i and selling on day j.
            // Calculate the profit obtained from this transaction.
            int profit = prices[j] - prices[i];

            // Update the maximum profit found so far.
            if (profit > max_profit) {
                max_profit = profit;
            }

            // If today's price is smaller than the current
            // minimum buying price, then today becomes the
            // best candidate for future buying.
            //
            // j can be used as the buying day for future
            // selling days because future iterations will have
            // index greater than j.
            if (prices[j] < prices[i]) {
                i = j;
            }
        }

        // Return the maximum profit.
        // If every possible transaction gives a loss,
        // max_profit remains 0.
        return max_profit;
    }
};