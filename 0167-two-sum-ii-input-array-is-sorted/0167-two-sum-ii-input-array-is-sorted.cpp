class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        // Since the array is sorted, we can use two pointers.
        int left = 0;
        int right = numbers.size() - 1;

        while(left < right)
        {
            int sum = numbers[left] + numbers[right];

            // We found the required pair.
            if(sum == target)
            {
                // LeetCode Two Sum II uses 1-based indexing.
                return {left + 1, right + 1};
            }

            // Current sum is too small.
            // Because the array is sorted, moving left forward
            // gives us a larger number and therefore increases the sum.
            else if(sum < target)
            {
                left++;
            }

            // Current sum is too large.
            // Moving right backward gives us a smaller number
            // and therefore decreases the sum.
            else
            {
                right--;
            }
        }

        // The problem guarantees that exactly one solution exists.
        return {};
    }
};