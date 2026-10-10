class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        int n = piles.size();

        priority_queue<int> pq;

        for( auto &it: piles)
        {
            pq.push( it );
        }

        while( !pq.empty() && k> 0)
        {
            int temp = pq.top();
            pq.pop();
            int temp2 = ceil(temp/2.0);
            pq.push(temp2);

            k--;
        }

        int result = 0;
        
        while( !pq.empty())
        {
            result += pq.top();
            pq.pop();
        }

        return result;
    }
};