class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        
        int n = nums.size();

        long long maxSum = 0;

        for( auto &x : nums)
        {
            if(x > 0)
            maxSum += x;
        }

        for(auto &x: nums)
        {
            x = abs(x);
        }

        sort(nums.begin(), nums.end());

        priority_queue< pair< long long, int>,vector<pair<long long , int>>, greater<pair<long long , int>>> pq;

        vector<long long> sums;

        sums.push_back(0);

        if(n>0)
        pq.push( {nums[0], 0});

        while( sums.size() < k)
        {
            auto[sum, index] = pq.top();
            pq.pop();

            sums.push_back(sum);

            if( index+1 < n)
            {
                pq.push( {sum + nums[index+1], index+1});

                pq.push( {sum + nums[index+1] - nums[index], index+1});

            }
        }

        return maxSum - sums[k-1];
    }
};