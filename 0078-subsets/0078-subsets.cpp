class Solution {
public:

    vector<vector<int>> ans;
    vector<int> Current_set;
    
    vector<vector<int>> printSubsets(vector<vector<int>> &ans, int index, vector<int> nums,vector<int>Current_set, int n)
    {
        if(index>=n)
        {
            ans.push_back(Current_set);
            return ans ;
        }

        Current_set.push_back(nums[index]);
        printSubsets(ans, index+1, nums, Current_set, n);

        Current_set.pop_back();
        printSubsets(ans, index+1, nums, Current_set, n);

        return ans;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        return printSubsets(ans, 0, nums,  Current_set, n);

    }
};