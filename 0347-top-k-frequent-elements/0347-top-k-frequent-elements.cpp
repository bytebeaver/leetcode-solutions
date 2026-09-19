class Solution {
public:

    typedef pair<int, int> P;

    struct lambda{
        bool operator()( P &p1, P &p2)
        {
            return p1.second > p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        priority_queue< P, vector<P> , lambda> pq;

        map<int, int> mp;

        for( auto &it: nums)
        {
            mp[it]++;
        }

        for( auto &it : mp)
        {
           
            pq.push( {it.first, it.second});
             if( pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<int> result;
        while(!pq.empty() && k>0)
        {
            P temp = pq.top();
            pq.pop();

            result.push_back( temp.first);
            k--;
        }

        return result;
    }
};