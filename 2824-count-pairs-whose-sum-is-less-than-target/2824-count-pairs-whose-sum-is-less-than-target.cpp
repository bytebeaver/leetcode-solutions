class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int l=0;
        int r= n-1;

        int ans = 0;
        while(l<r)
        {
            int sum = nums[l] + nums[r];

            if(sum >= target)
            r--;

            else if(sum < target)
            {
                ans += r-l;
                l++;
            }
        }

        return ans;
    }
};