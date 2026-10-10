
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {

        int n = piles.size();

        // Max-heap: keeps the largest pile at the top
        priority_queue<int> pq;

        // Stores the total number of stones in all piles
        int sum = 0;

        // Insert all piles into the max-heap and calculate the initial sum
        for (int i = 0; i < n; i++) {
            pq.push(piles[i]);
            sum += piles[i];
        }

        // Perform exactly k operations
        for (int i = 1; i <= k; i++) {

            // Select the pile containing the maximum number of stones
            int curr = pq.top();
            pq.pop();

            // Remove floor(curr / 2) stones from the selected pile
            // Integer division automatically calculates floor(curr / 2)
            // Example: curr = 9, remove = 9 / 2 = 4
            int remove = curr / 2;

            // Subtract the removed stones from the total sum
            sum -= remove;

            // Calculate the stones remaining in the selected pile
            // Example: 9 - 4 = 5
            int remaining = curr - remove;

            // Insert the updated pile back into the max-heap
            pq.push(remaining);
        }

        // Return the total number of stones remaining after k operations
        return sum;
    }
};
