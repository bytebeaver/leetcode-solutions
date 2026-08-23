class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> result;

        // Sorting by start value (default lexicographic sort) ensures that
        // overlapping intervals become adjacent to each other.
        sort(intervals.begin(), intervals.end());

        // start1, end1 act as a "running buffer" holding the current
        // merged interval that is still being built.
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        int n = intervals.size();

        for(int i=1; i<n; i++)
        {
            int start2 = intervals[i][0];
            int end2   = intervals[i][1];

            // merge karna hai ya nahi:
            // If current buffer's end reaches or crosses next interval's start,
            // they overlap (or touch), so merge is needed.
            if( end1 >= start2)
            {
                // merge krenge
                start1 = start1; // no-op; start stays same since sorted order guarantees start1 <= start2
                end1   = max(end1, end2); // extend buffer to cover the larger end

            }

            else
            {
                // No overlap — current buffer is complete, push it to result.
                result.push_back({start1, end1});

                // Start a fresh buffer with the new interval.
                start1 = start2;
                end1   = end2;
            }
            
        }

        // CRITICAL: the buffer always has one pending interval left after the loop
        // (whether it was standalone or the final merged group) — must flush it here.
        result.push_back({start1, end1});//last me ek interval bach jayega for loop mein

        return result;

    }
};