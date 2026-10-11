
class Solution {
public:

    // P stores {sum, {i, j}}, where i and j are indices
    // of the selected elements in nums1 and nums2.
    typedef pair<int, pair<int, int>> P;

    vector<vector<int>> kSmallestPairs(
        vector<int>& nums1, vector<int>& nums2, int k) {

        // Both arrays are already sorted in non-decreasing order
        int n = nums1.size();
        int m = nums2.size();

        // Min-heap: the pair with the smallest sum stays at the top
        priority_queue<P, vector<P>, greater<P>> pq;

        // Stores index pairs already inserted into the heap
        // to prevent processing the same pair more than once
        set<pair<int, int>> st;

        // Start with the pair of smallest elements: (0, 0)
        int sum = nums1[0] + nums2[0];
        pq.push({sum, {0, 0}});

        // Mark the initial index pair as visited
        st.insert({0, 0});

        vector<vector<int>> result;

        // Extract the k pairs with the smallest sums
        while (k > 0 && !pq.empty()) {

            // Get the pair having the smallest sum
            auto temp = pq.top();
            pq.pop();

            // Recover the indices of the selected elements
            int i = temp.second.first;
            int j = temp.second.second;

            // Store the actual values, not their indices
            result.push_back({nums1[i], nums2[j]});

            // Explore the next element in nums1 while keeping j fixed
            // This generates the neighboring pair (i+1, j)
            if (i + 1 < n && st.find({i + 1, j}) == st.end()) {

                int newSum = nums1[i + 1] + nums2[j];

                // Add the new candidate and mark its indices visited
                pq.push({newSum, {i + 1, j}});
                st.insert({i + 1, j});
            }

            // Explore the next element in nums2 while keeping i fixed
            // This generates the neighboring pair (i, j+1)
            if (j + 1 < m && st.find({i, j + 1}) == st.end()) {

                int newSum = nums1[i] + nums2[j + 1];

                // Add the new candidate and mark its indices visited
                pq.push({newSum, {i, j + 1}});
                st.insert({i, j + 1});
            }

            // One pair has been added to the result
            k--;
        }

        // Return up to k pairs in non-decreasing order of their sums
        return result;
    }
};
