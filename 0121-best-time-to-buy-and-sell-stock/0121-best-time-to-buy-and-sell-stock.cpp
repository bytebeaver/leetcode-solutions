class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int max_profit = 0; //agar hame loss hi ho rhaa hua har haal me to hm transaction krenge hi nahi to profit 0 hoga

        int i=0; //ith pointer is keeping track of the minimum price before the jth selling day 

        for( int j=1; j<n ; j++ )
        {

            //updating max_profit 
            if( prices[j] - prices[i] > max_profit)
            {
                max_profit = prices[j] - prices[i];
            }

            //updating the pointer to day with minimum byuing price
            //next iteration j will be j+1 and current j is a candidate for being the day with minimum byuing price
            if( prices[j] < prices[i])
            i=j;

        }

        return max_profit;

    }
};