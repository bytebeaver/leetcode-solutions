class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Stores: number -> index where that number was previously seen.
        // We use previously seen elements because the current element
        // will act as the second element of the pair.
        map<int, int> myMap;

        // Stores the two indices once we find a valid pair.
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++)
        {
            // If nums[i] is one element of the pair,
            // then we need (target - nums[i]) as the other element.
            int need = target - nums[i];

            // Check whether the required complement was already seen.
            // If yes, its stored index + current index form the answer.
            if(myMap.find(need) != myMap.end())
            {
                // Retrieve the index of the previously seen complement.
                ans.push_back(myMap[need]);

                // Add the current element's index.
                ans.push_back(i);

                // A valid pair has been found, so we can stop.
                return ans;
            }

            // No pair found yet.
            // Store the current number and its index so that
            // a future element can use it as its complement.
            myMap[nums[i]] = i;
        }

        // If no pair exists, return an empty vector.
        // For standard Two Sum, a solution is guaranteed to exist.
        return ans;
    }
};