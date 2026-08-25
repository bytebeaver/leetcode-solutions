class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0, j = 0;
        deque<int> q;      // non-increasing list, front = current max
        vector<int> ans;

        while (j < nums.size()) {
            // remove strictly smaller elements from back (they're useless now)
            while (!q.empty() > 0 && q.back() < nums[j])
                q.pop_back();

            q.push_back(nums[j]);   // insert current element

            if (j - i + 1 < k) {
                j++;                     // window still growing
            } else if (j - i + 1 == k) {
                ans.push_back(q.front());     // record current max

                if (q.front() == nums[i])      // leaving element was the max
                    q.pop_front();

                i++; j++;                // slide window forward
            }
        }
        return ans;
    }
};