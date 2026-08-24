class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();

        sort(nums.begin(), nums.end());


        vector< vector<int>> result;

        // if (n < 4)
        // return {};

        for(int i =0; i<=n-4; i++)
        {
            if(i>0 && nums[i] == nums[i-1])
            continue;

            for(int j = i+1; j<=n-3; j++)
            {
                if(j>i+1 && nums[j] == nums[j-1])
                continue;

                int l = j+1;
                int r=  n-1;

                while(l<r)
                {
                   long long sum = 1LL*nums[i] + 1LL*nums[j] + 1LL*nums[l] + 1LL*nums[r];

                    if(sum == target)
                    {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});

                        l++;
                        r--;

                        while(l<r  &&  nums[l] == nums[l-1])
                        l++;

                        while(l<r  &&  nums[r] == nums[r+1])
                        r--;
                    }

                    else if(sum > target)
                    r--;

                    else if(sum < target)
                    l++;
                    
                }
            }
        }

        return result;
    }
};