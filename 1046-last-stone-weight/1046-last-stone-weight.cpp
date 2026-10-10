class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        int n = stones.size();

        priority_queue<int> pq;
        for(auto &it : stones)
        {
            pq.push(it);
        }

        while( pq.size() > 1)
        {
            int heavy1 = pq.top();
            pq.pop();
            int heavy2 = pq.top();
            pq.pop();

            if( heavy1 == heavy2)
            {
                 if( pq.empty()) return 0;
                 continue;
            }

            else //heavy1 is more heavier
            pq.push( heavy1 - heavy2);

        }

        return pq.top();
    }
};