class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.begin() +n);
        vector<int> ans;

        for( int i=0; i<n-1; i++)
        {
            int var = nums[i];
            for(int j=0; j< nums[i+1]-nums[i]-1; j++)
            {     var +=1;
                 ans.push_back(var);
            }
        }

        return ans;
    }
};