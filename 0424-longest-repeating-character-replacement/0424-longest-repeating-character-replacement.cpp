class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.length();

        // Stores frequency of each uppercase character
        // char_freq[0] -> frequency of 'A'
        // char_freq[1] -> frequency of 'B'
        // ...
        // char_freq[25] -> frequency of 'Z'
        vector<int> char_freq(26, 0);

        // Maximum frequency of any single character
        // inside the current window
        int max_freq = 0;

        // Stores the maximum valid window length found
        int max_len = 0;

        // Sliding window
        int l = 0, r = 0;

        while (r < n)
        {
            // Add s[r] to the current window
            char_freq[s[r] - 'A']++;

            // Update maximum frequency
            max_freq = max(max_freq,
                           char_freq[s[r] - 'A']);

            // Check whether the current window is invalid
            //
            // Number of replacements required =
            // window length - frequency of most frequent character
            //
            // If this is greater than k,
            // we need to shrink the window.
            while ((r - l + 1) - max_freq > k)
            {
                // Remove the character at l
                char_freq[s[l] - 'A']--;

                // Recalculate maximum frequency
                // among all 26 characters
                max_freq = 0;

                for (int i = 0; i < 26; i++)
                {
                    max_freq = max(max_freq,
                                   char_freq[i]);
                }

                // Move left pointer forward
                l++;
            }

            // Current window is valid,
            // so update the maximum length.
            if ((r - l + 1) - max_freq <= k)
            {
                max_len = max(max_len,
                              r - l + 1);
            }

            // Expand the window
            r++;
        }

        return max_len;
    }
};