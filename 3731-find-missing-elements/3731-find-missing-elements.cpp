class Solution {
public:
    vector<int> approach1_sortAndFillGaps(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.begin() + n);   // sort so consecutive pairs make sense
    vector<int> ans;

    for (int i = 0; i < n - 1; i++)
    {
        // fill all numbers strictly between nums[i] and nums[i+1]
        for (int val = nums[i] + 1; val < nums[i+1]; val++)
        {
            ans.push_back(val);   // val is missing since it's not in nums
        }
    }

    return ans;
}

     vector<int> findMissingElements(vector<int>& nums) {
    map<int, bool> m;              // stores which numbers are present
    int min_ele = INT_MAX;
    int max_ele = INT_MIN;

    for (auto& val : nums)
    {
        m[val] = true;                       // mark val as present
        min_ele = min(min_ele, val);         // track smallest element
        max_ele = max(max_ele, val);         // track largest element
    }

    vector<int> ans;

    for (int i = min_ele + 1; i < max_ele; i++)
    {
        if (m.find(i) == m.end())            // i not present in map
            ans.push_back(i);                // so i is missing
    }

    return ans;
}
};