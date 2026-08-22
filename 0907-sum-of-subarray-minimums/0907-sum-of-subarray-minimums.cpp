class Solution {
public:

    // Finds the index of the PREVIOUS STRICTLY SMALLER element.
    //
    // Why >= here?
    // We remove elements that are greater than OR equal to arr[i].
    // Therefore, the element left on top must be strictly smaller.
    //
    // This also gives us our tie-breaking rule for duplicate values.
    vector<int> getPreviousSmallerOrEqual(vector<int>& arr) {

        int n = arr.size();

        vector<int> previousSmallerIndex(n);

        // Store indices, not values, because we need their positions
        // to calculate how many subarrays can use arr[i].
        stack<int> indexStack;

        for(int i = 0; i < n; i++)
        {
            // Remove elements that cannot be the previous boundary.
            //
            // If arr[stack.top()] >= arr[i], that element cannot remain
            // because arr[i] is smaller than or equal to it.
            //
            // Removing equal elements is also part of our duplicate
            // handling strategy.
            while(!indexStack.empty() &&
                  arr[indexStack.top()] >= arr[i])
            {
                indexStack.pop();
            }

            // If nothing is left, there is no smaller element on the left.
            if(indexStack.empty())
            {
                previousSmallerIndex[i] = -1;
            }
            else
            {
                // The remaining top is the nearest strictly smaller
                // element on the left.
                previousSmallerIndex[i] = indexStack.top();
            }

            // Current index becomes a candidate boundary for future elements.
            indexStack.push(i);
        }

        return previousSmallerIndex;
    }


    // Finds the index of the NEXT SMALLER-OR-EQUAL element.
    //
    // Why > here instead of >=?
    // We keep equal elements on the stack.
    //
    // This is deliberately opposite to the previous pass.
    // The asymmetry prevents duplicate minimums from claiming
    // the same subarray more than once.
    vector<int> getNextSmaller(vector<int>& arr) {

        int n = arr.size();

        vector<int> nextSmallerIndex(n);

        stack<int> indexStack;

        // Process from right to left because we need the next
        // smaller boundary on the right.
        for(int i = n - 1; i >= 0; i--)
        {
            // Remove only elements strictly greater than arr[i].
            //
            // Equal elements are kept so that duplicate values
            // are handled using our chosen tie-breaking rule.
            while(!indexStack.empty() &&
                  arr[indexStack.top()] > arr[i])
            {
                indexStack.pop();
            }

            // No smaller-or-equal element exists on the right.
            if(indexStack.empty())
            {
                nextSmallerIndex[i] = n;
            }
            else
            {
                // Nearest smaller-or-equal element on the right.
                nextSmallerIndex[i] = indexStack.top();
            }

            indexStack.push(i);
        }

        return nextSmallerIndex;
    }


    int sumSubarrayMins(vector<int>& arr) {

        const int MOD = 1e9 + 7;

        int n = arr.size();

        // Step 1:
        // Find the left boundary beyond which arr[i] cannot remain
        // the minimum of a subarray.
        vector<int> previousSmallerIndex =
            getPreviousSmallerOrEqual(arr);

        // Step 2:
        // Find the right boundary beyond which arr[i] cannot remain
        // the minimum.
        vector<int> nextSmallerIndex =
            getNextSmaller(arr);

        // Step 3:
        // Instead of generating every subarray, calculate the
        // contribution of each element.
        long long totalSum = 0;

        for(int i = 0; i < n; i++)
        {
            int previousIndex = previousSmallerIndex[i];
            int nextIndex = nextSmallerIndex[i];

            // Starting position can be any index from
            // previousIndex + 1 through i.
            //
            // Number of choices:
            // i - previousIndex
            int leftChoices = i - previousIndex;

            // Ending position can be any index from
            // i through nextIndex - 1.
            //
            // Number of choices:
            // nextIndex - i
            int rightChoices = nextIndex - i;

            // Every valid left choice can be paired with
            // every valid right choice.
            //
            // Therefore this is the number of subarrays
            // for which arr[i] is the selected minimum.
            int numberOfSubarrays =
                leftChoices * rightChoices;

            // arr[i] contributes its value once for every
            // subarray where it is the minimum.
            //
            // Cast to long long before multiplication to avoid
            // integer overflow.
            long long contribution =
                (long long)arr[i] * numberOfSubarrays;

            totalSum =
                (totalSum + contribution) % MOD;
        }

        return totalSum;
    }
};