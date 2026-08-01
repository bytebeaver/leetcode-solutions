class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int> myMap;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++)
        {
            int need = target - nums[i];

            if(myMap.find(need) != myMap.end())
             {
                ans.push_back(myMap[need]);
                ans.push_back(i);
                return ans;
             }

            myMap[nums[i]]=i;
        }

        return ans;
    }
};