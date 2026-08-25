class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0, j = 0;
        list<int> mylist;      // non-increasing list, front = current max
        vector<int> ans;

        while (j < nums.size()) {
            // remove strictly smaller elements from back (they're useless now)
            while (mylist.size() > 0 && mylist.back() < nums[j])
                mylist.pop_back();

            mylist.push_back(nums[j]);   // insert current element

            if (j - i + 1 < k) {
                j++;                     // window still growing
            } else if (j - i + 1 == k) {
                ans.push_back(mylist.front());     // record current max

                if (mylist.front() == nums[i])      // leaving element was the max
                    mylist.pop_front();

                i++; j++;                // slide window forward
            }
        }
        return ans;
    }
};