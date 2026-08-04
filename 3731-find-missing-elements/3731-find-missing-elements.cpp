class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.begin() +n);
        vector<int> ans;

        for( int i=0; i<n-1; i++)
        {
            for(int val = nums[i] + 1; val < nums[i+1]; val++)
            {
                ans.push_back(val);
            }
        }

        return ans;
    }
};