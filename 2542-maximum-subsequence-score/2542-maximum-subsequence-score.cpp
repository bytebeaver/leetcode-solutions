
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        int n = nums1.size();

        // Store corresponding elements as {nums1[i], nums2[i]}
        vector<pair<int, int>> vec(n);

        for (int i = 0; i < n; i++) {
            vec[i] = {nums1[i], nums2[i]};
        }

        // Sort pairs in ascending order of nums2
        // The current nums2 value will be the minimum among
        // all pairs processed so far
        auto lambda = [&](auto &p1, auto &p2) {
            return p1.second > p2.second;
        };

        sort(begin(vec), end(vec), lambda);

        // Min-heap maintains the k largest nums1 values
        // among the elements considered so far
        priority_queue<int, vector<int>, greater<int>> pq;

        // Sum of the nums1 values currently selected in the heap
        long long ksum = 0;

        // Initialize the heap with the first k elements
        for (int i = 0; i < k; i++) {
            ksum += vec[i].first;
            pq.push(vec[i].first);
        }

        // Initial score: sum of nums1 multiplied by minimum nums2
        // Since nums2 is sorted, the minimum is vec[k-1].second
        long long result = ksum * vec[k - 1].second;

        // Consider each remaining pair as a potential minimum nums2
        for (int i = k; i < n; i++) {

            // Include the current nums1 value in the sum
            ksum += vec[i].first;

            // Remove the smallest nums1 value to retain only k elements
            ksum -= pq.top();
            pq.pop();

            // Insert the current nums1 value into the heap
            pq.push(vec[i].first);

            // Calculate the score using the current nums2 as the minimum
            // Update the maximum score found so far
            result = max(result, ksum * 1LL * vec[i].second);
        }

        return result;
    }
};
