class Solution {
public:

    // Finds the index of the previous STRICTLY smaller element.
    //
    // We remove elements >= arr[i].
    // Therefore, after popping, the stack top (if any)
    // must contain a value strictly smaller than arr[i].
    //
    // Removing equal values here is also important for
    // handling duplicate minimums without double counting.
    vector<int> getPreviousStrictlySmaller(vector<int>& arr) {

        int n = arr.size();

        // previousSmallerIndex[i] = nearest index to the left
        // whose value is strictly smaller than arr[i].
        vector<int> previousSmallerIndex(n);

        // Stores indices of elements that are still possible
        // previous-smaller candidates.
        stack<int> indexStack;

        for(int i = 0; i < n; i++)
        {
            // Remove elements that are greater than or equal to arr[i].
            //
            // They cannot be the previous strictly smaller element.
            while(!indexStack.empty() &&
                  arr[indexStack.top()] >= arr[i])
            {
                indexStack.pop();
            }

            if(indexStack.empty())
            {
                // No smaller element exists on the left.
                // -1 acts as a boundary outside the array.
                previousSmallerIndex[i] = -1;
            }
            else
            {
                // Stack top is the nearest strictly smaller element.
                previousSmallerIndex[i] = indexStack.top();
            }

            // Current index becomes a candidate for future elements.
            indexStack.push(i);
        }

        return previousSmallerIndex;
    }


    // Finds the index of the next SMALLER-OR-EQUAL element.
    //
    // We remove only elements > arr[i].
    // Therefore equal values remain on the stack.
    //
    // This is intentionally different from the previous pass.
    // The asymmetry handles duplicate minimum values correctly.
    vector<int> getNextSmallerOrEqual(vector<int>& arr) {

        int n = arr.size();

        // nextSmallerOrEqualIndex[i] = nearest index to the right
        // whose value is smaller than or equal to arr[i].
        vector<int> nextSmallerOrEqualIndex(n);

        stack<int> indexStack;

        // Traverse from right to left because we want
        // the nearest valid element on the right.
        for(int i = n - 1; i >= 0; i--)
        {
            // Remove elements strictly greater than arr[i].
            //
            // Equal elements are intentionally kept.
            while(!indexStack.empty() &&
                  arr[indexStack.top()] > arr[i])
            {
                indexStack.pop();
            }

            if(indexStack.empty())
            {
                // No smaller-or-equal element exists on the right.
                // n acts as a boundary outside the array.
                nextSmallerOrEqualIndex[i] = n;
            }
            else
            {
                // Stack top is the nearest smaller-or-equal element.
                nextSmallerOrEqualIndex[i] = indexStack.top();
            }

            indexStack.push(i);
        }

        return nextSmallerOrEqualIndex;
    }


    int sumSubarrayMins(vector<int>& arr) {

        const int MOD = 1e9 + 7;

        int n = arr.size();

        // For every index i:
        // previousSmallerIndex[i] tells us where we must stop
        // when extending the subarray to the left.
        vector<int> previousSmallerIndex =
            getPreviousStrictlySmaller(arr);

        // nextSmallerOrEqualIndex[i] tells us where we must stop
        // when extending the subarray to the right.
        vector<int> nextSmallerOrEqualIndex =
            getNextSmallerOrEqual(arr);

        long long totalSum = 0;

        for(int i = 0; i < n; i++)
        {
            int previousIndex = previousSmallerIndex[i];
            int nextIndex = nextSmallerOrEqualIndex[i];

            // We can choose any starting index from
            // previousIndex + 1 through i.
            //
            // Number of possible starting positions.
            int leftBoundaryChoices = i - previousIndex;

            // We can choose any ending index from
            // i through nextIndex - 1.
            //
            // Number of possible ending positions.
            int rightBoundaryChoices = nextIndex - i;

            // Every valid starting position can be paired
            // with every valid ending position.
            //
            // Hence this is the number of subarrays for which
            // arr[i] is the selected minimum.
            int subarrayCount =
                leftBoundaryChoices * rightBoundaryChoices;

            // arr[i] contributes its value once for each
            // subarray where it is the minimum.
            long long contribution =
                (long long)arr[i] * subarrayCount;

            totalSum =
                (totalSum + contribution) % MOD;
        }

        return totalSum;
    }
};