class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n = nums.size();

        map<int, int> mp;//store krega ki maine koi sum kitni baar dekha hai

        int sum = 0;
        
        mp[0] = 1;
        
        int count = 0;
        for(int i=0; i<n ; i++)
        {
            sum += nums[i];

            //uptil now the sum of total elements can be see as goal + (sum-goal) if i have seen (sum-k) at a previous index then from that index+1 till now the sum will be k ..... lets call that (sum-k) to be prefix_sum

            int prefix_sum = sum - goal;

            if( mp.find( prefix_sum) != mp.end())
            {
                count += mp[ prefix_sum];
            }

            mp[sum]++;
        }

        return count;
    }
};