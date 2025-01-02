class Solution { 
public:

    // Helper function to check if a character is a vowel
    bool isVowel(char &ch) {
        // Check if the character is one of the vowels: 'a', 'e', 'i', 'o', 'u'
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true; // Return true if it's a vowel
        return false; // Return false otherwise
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int Q = queries.size(); // Number of queries
        int N = words.size();   // Number of words

        vector<int> result(Q);       // Result array to store answers for each query
        vector<int> cummulative_sum(N); // Cumulative sum array to store the count of vowel-strings up to each index

        int sum = 0; // Counter to track the number of strings that start and end with vowels

        // Step 1: Populate the cumulative sum array
        for (int i = 0; i < N; i++) {
            // Check if the first and last characters of the current word are vowels
            if (isVowel(words[i][0]) && isVowel(words[i].back())) 
                sum++; // Increment the count if both conditions are true

            cummulative_sum[i] = sum; // Store the cumulative count at index i
        }

        // Step 2: Process each query using the cumulative sum array
        for (int i = 0; i < Q; i++) {
            int l = queries[i][0]; // Left index of the query range
            int r = queries[i][1]; // Right index of the query range

            // If the left index is not 0, subtract the cumulative sum up to l-1 from r
            if (l != 0) {
                result[i] = cummulative_sum[r] - cummulative_sum[l - 1];
            } 
            else {
                // If l == 0, take the cumulative sum up to r
                result[i] = cummulative_sum[r];
            }
        }

        return result; // Return the result array
    }
};

/*
ALGORITHM STEPS:
1. Define a helper function `isVowel` to check if a character is a vowel.
2. Initialize variables:
   - `Q` for the number of queries.
   - `N` for the number of words.
   - `result` array to store answers for each query.
   - `cumulative_sum` array to store the number of vowel-strings up to each index.
   - `sum` to track the count of vowel-strings.
3. Iterate through the `words` array:
   - Check if a word starts and ends with a vowel using `isVowel`.
   - If true, increment `sum`.
   - Update `cumulative_sum[i]` with the value of `sum`.
4. For each query `[l, r]`:
   - If `l` is not 0, calculate the result as `cumulative_sum[r] - cumulative_sum[l-1]`.
   - If `l` is 0, set the result to `cumulative_sum[r]`.
5. Return the `result` array.

DRY RUN EXAMPLE:

Input:
words = ["aba", "bcb", "ece", "aa", "e"]
queries = [[0, 2], [1, 4], [1, 1]]

Step 1: Initialize and compute `cumulative_sum`.
- words[0] = "aba", starts and ends with vowels -> cumulative_sum[0] = 1
- words[1] = "bcb", does not -> cumulative_sum[1] = 1
- words[2] = "ece", starts and ends with vowels -> cumulative_sum[2] = 2
- words[3] = "aa", starts and ends with vowels -> cumulative_sum[3] = 3
- words[4] = "e", starts and ends with vowels -> cumulative_sum[4] = 4

cumulative_sum = [1, 1, 2, 3, 4]

Step 2: Process each query.
- Query [0, 2]: result = cumulative_sum[2] = 2
- Query [1, 4]: result = cumulative_sum[4] - cumulative_sum[0] = 4 - 1 = 3
- Query [1, 1]: result = cumulative_sum[1] - cumulative_sum[0] = 1 - 1 = 0

Final result: [2, 3, 0]
Output: [2, 3, 0]
*/