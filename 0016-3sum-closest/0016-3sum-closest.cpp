class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        
        int candidate = INT_MAX;
        int ans;
        for(int i=0; i<=n-2; i++)
        {

            if(i> 0 && nums[i] == nums[i-1])
            continue;

            int l = i+1;
            int r = n-1;

            while(l<r)
            {
                int sum = nums[i] + nums[l] + nums[r];

                if(sum == target)
                {
                    ans = target;
                    return ans;
                }

                else
                {
                    int diff = abs(target - sum);

                    if(diff < candidate)
                    {
                        candidate = diff;
                        ans = sum;
                    }

                    if(sum < target)
                    {
                    l++;
                        if(l<r && nums[l] == nums[l-1])
                        l++;
                    }
                    

                    else if(sum > target)
                    {
                    r--;
                        if(l<r && nums[r] == nums[r+1])
                        r--;
                    }
                   
                }
            }
        }


        return ans;
    }
};