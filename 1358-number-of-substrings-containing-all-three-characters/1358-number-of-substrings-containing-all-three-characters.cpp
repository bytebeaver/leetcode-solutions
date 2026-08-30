class Solution {
public:
    int numberOfSubstrings(string s) {
        
        // count = total number of valid substrings
        int count = 0;

        // n = length of the string
        int n = s.length();

        // Sliding window pointers
        int l = 0, r = 0;

        // Stores frequency of characters in current window
        // freq[0] -> frequency of 'a'
        // freq[1] -> frequency of 'b'
        // freq[2] -> frequency of 'c'
        vector<int> char_freq(3, 0);

        while (r < n)
        {
            // Add the current character s[r] to the window.
            //
            // s[r] - 'a' converts:
            // 'a' -> 0
            // 'b' -> 1
            // 'c' -> 2
            //
            // So we increment the frequency of s[r].
            char_freq[s[r] - 'a']++;

            // If the current window contains at least
            // one 'a', one 'b' and one 'c', then it is valid.
            while (char_freq[0] >= 1 &&
                   char_freq[1] >= 1 &&
                   char_freq[2] >= 1)
            {
                // Current window [l...r] contains a, b and c.
                //
                // Therefore, every substring obtained by
                // extending r towards the end will also
                // contain a, b and c.
                //
                // Valid substrings are:
                // [l...r], [l...r+1], ..., [l...n-1]
                //
                // Number of such substrings = n - r.
                count += n - r;

                // Remove the character at index l
                // before moving l forward.
                //
                // s[l] - 'a' tells us whether it is
                // 'a' (0), 'b' (1), or 'c' (2).
                char_freq[s[l] - 'a']--;

                // Shrink the window from the left.
                l++;
            }

            // Expand the window by moving r forward.
            r++;
        }

        // Return total number of substrings
        // containing at least one a, b and c.
        return count;
    }
};