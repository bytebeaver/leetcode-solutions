class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
        int n = costs.size();

        priority_queue<int, vector<int> ,greater<int>> pq1, pq2;

        int hired = 0;

        long long ans = 0;

        int i=0;
        int j=n-1;

        while(hired < k)
        {
            while( pq1.size() < candidates && i<=j)
            {
                pq1.push( costs[i] );
                i++;
            }

             while( pq2.size() < candidates && j>=i)
            {
                pq2.push( costs[j] );
                j--;
            }

            int min_from_pq1 = ( pq1.size() > 0)?pq1.top(): INT_MAX;
            int min_from_pq2 = ( pq2.size() > 0)?pq2.top(): INT_MAX;

            if( min_from_pq1 <= min_from_pq2)
            {
                ans+= min_from_pq1;
                pq1.pop();
            }
            else
            {
                ans += min_from_pq2;
                pq2.pop();
            }

            hired++;
        }

    return ans;
    }
};