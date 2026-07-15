class Solution {
public:

    vector<vector<int>> ans;
    vector<int> Current_set;

    // ALGORITHM: Take / Not-Take recursion (a.k.a. Subset/Power-Set generation)
    // ---------------------------------------------------------------------
    // For every element in nums, we have exactly 2 choices:
    //   1) TAKE it   -> include nums[index] in Current_set, recurse further
    //   2) DON'T TAKE it -> skip nums[index], recurse further
    //
    // Example: nums = [1, 2]
    //
    //                        index=0, set=[]
    //                       /                \
    //              TAKE 1                  DON'T TAKE 1
    //           index=1,set=[1]           index=1,set=[]
    //           /          \                /          \
    //      TAKE 2      DON'T TAKE 2    TAKE 2      DON'T TAKE 2
    //   set=[1,2]      set=[1]        set=[2]        set=[]
    //   index=2        index=2        index=2        index=2
    //   (base case)    (base case)    (base case)    (base case)
    //
    // At each of the 4 leaves (base cases), we've made a full decision
    // for every element -> that leaf's "Current_set" is one valid subset.
    // Collecting all leaves gives: [1,2], [1], [2], [] -> all 4 subsets. 

    vector<vector<int>> printSubsets(vector<vector<int>> &ans, int index, vector<int> nums, vector<int> Current_set, int n)
    {
        // BASE CASE: we've decided take/not-take for every index (0 to n-1).
        // So Current_set now represents one COMPLETE subset -> record it.
        if (index >= n)
        {
            ans.push_back(Current_set);
            return ans;
        }

        // CHOICE 1: TAKE nums[index] into the current subset
        Current_set.push_back(nums[index]);
        printSubsets(ans, index + 1, nums, Current_set, n);

        // CHOICE 2: DON'T TAKE nums[index] -> undo the take (backtrack)
        // and explore the "leave it out" branch instead.
        Current_set.pop_back();
        printSubsets(ans, index + 1, nums, Current_set, n);

        // Both branches (take & not-take) have already pushed their
        // results into 'ans' by reference, so just return it.
        return ans;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        return printSubsets(ans, 0, nums, Current_set, n);
    }
};


/*Intuition
Think of it like packing a suitcase item by item. For every item on your list, you stand at a fork: "do I pack this one, or not?" You make that decision for item 1, then for item 2, and so on, down to the last item. By the time you've made a take/leave decision for every item, whatever combination sits in your suitcase right then is exactly one valid subset — so you record it.
Since every item independently branches into 2 choices (take / leave), and there are n items, you naturally get 2^n total leaves in this decision tree — which is exactly the number of subsets a set of size n has (including the empty set and the full set itself).
Time Complexity: O(n · 2ⁿ)

There are 2^n leaf nodes (complete subsets), since each of the n elements doubles the number of branches.
At each leaf, ans.push_back(Current_set) copies a vector of size up to n → O(n) work.
Total: 2^n leaves × O(n) copy cost = O(n · 2ⁿ).

Space Complexity: O(n) for the recursion, or O(n · 2ⁿ) if you count the output.

Auxiliary/recursion stack space: O(n) — the recursion goes n levels deep at most (one call per index), and Current_set also holds at most n elements at a time.
Output space: storing all 2^n subsets, each up to size n, takes O(n · 2ⁿ) — but this is usually not counted against "extra" space since it's the required output itself.*/