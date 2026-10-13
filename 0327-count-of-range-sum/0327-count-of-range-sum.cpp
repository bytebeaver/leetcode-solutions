
class Solution {
public:
    vector<long long> segTree;
    vector<long long> coords;

    // Build a segment tree with all frequencies initially 0
    void build(int node, int l, int r) {
        if (l == r) {
            segTree[node] = 0;
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        segTree[node] = segTree[2 * node]
                      + segTree[2 * node + 1];
    }

    // Increase the frequency at index idx by 1
    void update(int node, int l, int r, int idx) {
        if (l == r) {
            segTree[node]++;
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid) {
            update(2 * node, l, mid, idx);
        } else {
            update(2 * node + 1, mid + 1, r, idx);
        }

        segTree[node] = segTree[2 * node]
                      + segTree[2 * node + 1];
    }

    // Count frequencies in the index range [start, end]
    long long query(int node, int l, int r,
                    int start, int end) {

        // No overlap
        if (l > end || r < start)
            return 0;

        // Complete overlap
        if (l >= start && r <= end)
            return segTree[node];

        int mid = l + (r - l) / 2;

        return query(2 * node, l, mid, start, end)
             + query(2 * node + 1, mid + 1, r, start, end);
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        // Step 1: Calculate prefix sums
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // Step 2: Coordinate compression
        // Store all prefix sums in sorted order
        coords = prefix;

        sort(coords.begin(), coords.end());

        coords.erase(
            unique(coords.begin(), coords.end()),
            coords.end()
        );

        int m = coords.size();

        // Step 3: Build the frequency segment tree
        segTree.resize(4 * m, 0);
        build(1, 0, m - 1);

        long long ans = 0;

        // Step 4: Process each prefix sum
        for (int i = 0; i <= n; i++) {
            long long curr = prefix[i];

            // We need earlier prefix sums in:
            // [curr - upper, curr - lower]
            long long lowValue = curr - upper;
            long long highValue = curr - lower;

            // Find the compressed index range
            int left = lower_bound(
                coords.begin(), coords.end(), lowValue
            ) - coords.begin();

            int right = upper_bound(
                coords.begin(), coords.end(), highValue
            ) - coords.begin() - 1;

            // Count valid earlier prefix sums
            if (left <= right) {
                ans += query(1, 0, m - 1, left, right);
            }

            // Insert current prefix sum for future queries
            int idx = lower_bound(
                coords.begin(), coords.end(), curr
            ) - coords.begin();

            update(1, 0, m - 1, idx);
        }

        return (int)ans;
    }
};
