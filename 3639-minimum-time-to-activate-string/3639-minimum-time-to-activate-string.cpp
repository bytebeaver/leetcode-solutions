class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {

        int n = order.size();

        // Stores positions where '*' currently exists.
        // -1 and n are dummy boundaries.
        set<int> star_idx_set;
        star_idx_set.insert(-1);
        star_idx_set.insert(n);

        // Total number of valid substrings so far.
        long long count = 0;

        for (int t = 0; t < n; t++) {

            // Position where the new '*' is inserted.
            int x = order[t];

            // Insert the new star position.
            star_idx_set.insert(x);

            // Find the inserted position.
            auto it = star_idx_set.find(x);

            // Closest star on the left.
            int before = *prev(it);

            // Closest star on the right.
            int after = *next(it);

            // Number of possible starts = x - before
            // Number of possible ends   = after - x
            // Multiply because every start can pair with every end.
            long long new_substrings =
                1LL * (x - before) * (after - x);

            // Add only the newly created valid substrings.
            count += new_substrings;

            // String becomes active.
            if (count >= k) {
                return t;
            }
        }

        // Never reached k.
        return -1;
    }
};