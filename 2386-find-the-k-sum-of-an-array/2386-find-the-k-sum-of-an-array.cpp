
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: Calculate maximum subsequence sum
        long long maxSum = 0;
        for (int x : nums) {
            if (x > 0)
                maxSum += x;
        }

        // Step 2: Convert all elements to absolute values
        for (int &x : nums)
            x = abs(x);

        // Step 3: Sort absolute values
        sort(nums.begin(), nums.end());

        // Step 4: Min-heap stores {sum, index}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        // Store the k smallest subset sums in this array.
        vector<long long> sums;

        // Empty subset has sum 0.
        sums.push_back(0);

        // First non-empty subset
        if (n > 0)
            pq.push({nums[0], 0});

        // Generate sums until we have k of them.
        while (sums.size() < k) {
            auto [sum, idx] = pq.top();
            pq.pop();

            // This is the next smallest subset sum.
            sums.push_back(sum);

            // Add the next element to the current subset.
            if (idx + 1 < n) {
                pq.push({sum + nums[idx + 1], idx + 1});

                // Replace the current element with the next one.
                pq.push({
                    sum - nums[idx] + nums[idx + 1],
                    idx + 1
                });
            }
        }

        // kth smallest decrease gives the kth largest subsequence sum.
        return maxSum - sums[k - 1];
    }
};
