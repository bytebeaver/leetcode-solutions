/*
//recursive approach ----striver

class Solution {
public:
    int MaxSum(vector<int> &nums, int index)
    {
        if(index==0)              // only one element left -> no conflict, must take it
        return nums[index];

        if(index<0)                // no elements left at all -> contributes nothing
        return 0;

        int pick = nums[index] + MaxSum(nums, index-2);   // take current, skip adjacent one
        int not_pick =       0 + MaxSum(nums, index-1);    // skip current, previous is free

        return max(pick, not_pick);
    }

    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        return MaxSum(nums, n-1);   // start from the last index, work backward
    }
};


//memoization:

class Solution {
public:
    int MaxSum(vector<int> &nums, int index, vector<int> &dp)
    {
        if(index==0)                    // only one element left -> no conflict, must take it
        return nums[index];

        if(index<0)                      // nothing left at all -> contributes nothing
        return 0;

        if(dp[index]!= -1)                // already solved before -> instant O(1) answer
        return dp[index];

        int pick = nums[index] + MaxSum(nums, index-2, dp);   // take current, skip adjacent
        int not_pick =       0 + MaxSum(nums, index-1, dp);    // skip current, previous is free

        return dp[index] = max(pick, not_pick);    // store AND return this index's answer
    }

    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);           // -1 means "not computed yet"
        return MaxSum(nums, n-1, dp);
    }
};

//tabulation

//without space optimization

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];               // sirf ek hi house
        if(n == 2) return max(nums[0], nums[1]);  // dono adjacent, max lo

        vector<int> dp(n, 0);

        dp[0] = nums[0];                  // base case 1
        dp[1] = max(nums[0], nums[1]);    // base case 2

        int i = 2;
        while(i < n) {
            int take = dp[i-2] + nums[i]; // is house rob karo
            int not_take = dp[i-1];       // is house skip karo

            dp[i] = max(take, not_take);  // best choice store karo

            i++;
        }

        return dp[n-1]; // last house tak ka max loot
    }
};





class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];               // sirf ek house
        if(n == 2) return max(nums[0], nums[1]);  // dono adjacent, max lo

        vector<int> dp(n, 0);

        dp[n-1] = nums[n-1];                      // base case: last house
        dp[n-2] = max(nums[n-1], nums[n-2]);      // base case: last do houses

        int i = n - 3;
        while(i >= 0) {
            int take = dp[i+2] + nums[i];  // is house rob karo
            int not_take = dp[i+1];        // is house skip karo

            dp[i] = max(take, not_take);   // best choice store karo

            i--;
        }

        return dp[0]; 
    }
};
*/

//tabulation with space optimization

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];               // ek hi house
        if(n == 2) return max(nums[0], nums[1]);  // dono adjacent, max lo

        int prev  = nums[0];  // dp[0] jaisa -> one-back answer
        int prev2 = 0;        // dp[-1] jaisa -> two-back answer (phantom base)

        for(int i = 1; i < n; i++) {
            int take = nums[i] + prev2;  // is house rob karo
            int not_take = prev;         // is house skip karo

            int current_i = max(take, not_take); // best till index i

            prev2 = prev;        // window slide: prev -> prev2
            prev = current_i;    // window slide: current -> prev
        }

        return prev; // last index tak ka max answer
    }
};





