class Solution {
public:

    typedef pair< int, pair<int, int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        priority_queue< P, vector<P>> pq; //max-heap

        int n = nums1.size();
        int m = nums2.size();

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m ; j++)
            {
                int sum = nums1[i] + nums2[j];

                if( pq.size() <k)
                pq.push( { sum, {i,j} } );

                else if( pq.size() >= k)
                {
                    if( sum < pq.top().first)
                    {
                        pq.pop();
                        pq.push( { sum, {i,j} } );
                    }

                    else if(sum >= pq.top(). first)
                    break; //agr nums1[i] + nums2[j] >= pq.top().first hain to nums 2 me aane wale age sare elements ke liye bhi ye true hoga ...isliye hm break kr jate hain and nums1 me i ko aage badhate hain      
                }
            }
        }

        vector<vector<int>> result;

        while( !pq.empty())
        {
            auto temp = pq.top(); //pq.top will be like { sum , {i,j}}
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            result.push_back( {nums1[i], nums2[j]});

        }        

        return result;
    }
};