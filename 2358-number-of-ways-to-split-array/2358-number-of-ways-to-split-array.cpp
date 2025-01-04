//CodewithMIK

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // Get the size of the input array
        int n = nums.size();

        // Variable to store the total sum of all elements in the array
        long long total_sum = 0;

        // Calculate the total sum of the array elements
        for (int &num : nums) {
            total_sum += num;
        }

        // Initialize a counter for valid splits
        int split = 0;

        // Initialize the cumulative sum of the left part
        long long leftsum = 0;

        // Iterate through the array till index n-2
        // Reason: We need to ensure that there's at least one element on the right part
        // At i = n-1, the right part would be empty, violating the problem's constraints
        for (int i = 0; i <= n - 2; i++) {
            // Add the current element to the left part's sum
            leftsum += nums[i];

            // Calculate the right part's sum
            // This is done by subtracting the left part's sum from the total sum
            long long rightsum = total_sum - leftsum;

            // Check if the left part's sum is greater than or equal to the right part's sum
            if (leftsum >= rightsum) {
                // If valid, increment the split counter
                split++;
            }
        }

        // Return the total number of valid splits
        return split;
    }
};

/*
Algorithm Steps:
1. Initialize the total sum of the array.
2. Iterate through the array to calculate the total sum.
3. Initialize variables for counting valid splits and the cumulative left sum.
4. Loop through the array until index n-2 (ensuring at least one element remains in the right part):
   a. Update the left sum by adding the current element.
   b. Calculate the right sum as total_sum - leftsum.
   c. Check if leftsum >= rightsum. If true, increment the split counter.
5. Return the total number of valid splits.

Example Test Case:
Input: nums = [10, 4, -8, 7]
Steps:
- Total sum: 10 + 4 + (-8) + 7 = 13
- Loop through the array till n-2:
  i = 0: leftsum = 10, rightsum = 13 - 10 = 3 -> valid (10 >= 3), split = 1
  i = 1: leftsum = 10 + 4 = 14, rightsum = 13 - 14 = -1 -> valid (14 >= -1), split = 2
  i = 2: leftsum = 14 + (-8) = 6, rightsum = 13 - 6 = 7 -> invalid (6 < 7)
Output: 2
*/
 
// Intuition Behind the Code
// The goal of the problem is to determine how many ways the array can be split into two non-empty parts such that the sum of the left part is greater than or equal to the sum of the right part. Here's the intuition behind your approach:

// Breaking Down the Problem:
// At every index i, the array is split into two parts:
// Left part: Includes elements from index 0 to i (inclusive).
// Right part: Includes elements from index i+1 to n-1.
// To satisfy the condition, the sum of the left part (leftsum) must be greater than or equal to the sum of the right part (rightsum).
// Key Insight:
// Calculating the sum of both parts naively for every split would be inefficient, especially for large arrays. Instead:
// Precompute the total sum of the array.
// Use the cumulative sum of the left part (leftsum) to dynamically compute the right part's sum:

// rightsum = total_sum − leftsum

// This avoids recomputing the sum for the right part repeatedly, reducing the time complexity to 
// \U0001d442(n)

// Why Loop Until 
// n−2?
// At index 
// i=n−2, the left part includes elements from 0 to n-2 (inclusive), and the right part includes only the element at index n-1. This ensures both parts are non-empty.
// Beyond 
// i=n−2, the right part would be empty, which is invalid.

// Efficient Comparison:
// As you iterate through the array:
// Update leftsum by adding the current element.
// Compute rightsum using the formula.
// Compare leftsum and rightsum to determine if the split at index i is valid.
// Increment the counter for valid splits if the condition is satisfied.
