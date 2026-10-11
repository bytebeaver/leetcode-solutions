class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();

        vector< pair<int, int>> vec(n);

        for(int i=0; i<n; i++)
        {
            vec[i] = {nums1[i], nums2[i]};
        }

        auto lambda = [&] (auto &p1 , auto &p2)
        {
            return p1.second > p2.second;
        };

        sort( begin(vec), end(vec), lambda);

        priority_queue< int , vector<int>, greater<int> >pq;
         
        long long ksum = 0;
        for( int i=0; i<=k-1; i++)  //getting  sum of first k elements of nums1
        {
            ksum += 1LL*vec[i].first;
            pq.push( vec[i].first );
        }

        long long result = ksum * 1LL*(vec[k-1].second);
         
        for(int i=k; i<n; i++)
        {
            ksum += 1LL*vec[i].first;

            ksum -= 1LL*pq.top();
            pq.pop();
            pq.push( vec[i].first);
            result = max(result, ksum *1LL* ( vec[i].second ));
        }

        return result;
    }
};