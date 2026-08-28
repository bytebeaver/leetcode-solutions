class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        // Store the total number of fruits in the array.
        int n = fruits.size();

        // Map stores:
        // fruit type -> number of times that fruit
        // occurs inside the current window.
        map<int, int> mp;

        // i represents the left boundary of
        // the current sliding window.
        int i = 0;

        // j represents the right boundary of
        // the current sliding window.
        int j = 0;

        // Stores the maximum length of a valid
        // window found so far.
        int count = 0;

        // Continue expanding the window while
        // j is within the array.
        while (j < n)
        {
            // Add fruits[j] to the current window
            // and increase its frequency in the map.
            mp[fruits[j]]++;

            // If there are at most 2 different fruit types,
            // the current window can fit into the two baskets.
            if (mp.size() <= 2)
            {
                // Calculate the size of the current window.
                // Since both i and j are inclusive:
                // length = j - i + 1
                count = max(count, j - i + 1);
            }

            // If there are more than 2 different fruit types,
            // the current window is not valid.
            else if (mp.size() > 2)
            {
                // Remove one occurrence of the fruit
                // at the left boundary of the window.
                mp[fruits[i]]--;

                // If its frequency becomes zero,
                // there are no more occurrences of this
                // fruit type in the current window.
                if (mp[fruits[i]] == 0)
                {
                    // Remove the fruit type completely
                    // from the map.
                    mp.erase(fruits[i]);
                }

                // Move the left boundary one position right.
                i++;
            }

            // Move the right boundary one position right
            // to process the next fruit.
            j++;
        }

        // Return the maximum valid window length found.
        return count;
    }
};