class Solution {
public:
//     vector<int> findMissingElements(vector<int>& nums) {
        
//         int n = nums.size();
//         sort(nums.begin(), nums.begin() +n);
//         vector<int> ans;

//         for( int i=0; i<n-1; i++)
//         {
//             for(int val = nums[i] + 1; val < nums[i+1]; val++)
//             {
//                 ans.push_back(val);
//             }
//         }

//         return ans;
//     }


     vector<int> findMissingElements(vector<int>& nums) {
        
       int n = nums.size();

       map<int, bool> m;

        int min_ele = INT_MAX;
        int max_ele = INT_MIN;

       for(auto & val : nums)
       {
            m[val] = true;
            min_ele =min(min_ele, val);
            max_ele =max(max_ele, val);
       }


        vector<int> ans;


       for(int i=min_ele+1; i<max_ele; i++)
       {
            if(m.find(i) == m.end() )
            ans.push_back(i);
       }

    return ans;
    }
};