class Solution {
public:

    string minWindow(string s, string t) {

        // Stores the frequency of each character required from t.
        //
        // Example:
        // t = "AABC"
        //
        // char_freq:
        // A -> 2
        // B -> 1
        // C -> 1
        //
        // The values will become smaller as we find the
        // required characters inside our current window.
        unordered_map<char, int> char_freq;


        int n = s.length();
        int m = t.length();


        // 'count' represents the number of characters from t
        // that have been matched in the current window.
        //
        // Since duplicates matter, every occurrence is counted.
        //
        // Example:
        // t = "AABC"
        // We need 4 characters in total.
        //
        // count == 4 means the current window contains
        // all required characters.
        int count = 0;


        // Stores the length of the smallest valid window found.
        //
        // Initially, we have not found any valid window,
        // so we use INT_MAX.
        int min_length = INT_MAX;


        // Stores the starting index of the smallest valid window.
        //
        // -1 means that no valid window has been found yet.
        int start_index = -1;


        // Sliding window pointers.
        //
        // Current window is:
        // [l ........ r]
        int l = 0;
        int r = 0;


        // Store the frequency of every character in t.
        for(int i = 0; i < m; i++)
        {
            char_freq[t[i]]++;
        }


        // Expand the window by moving r from left to right.
        while(r < n)
        {

            // If s[r] is still required, then this character
            // contributes towards satisfying t.
            //
            // char_freq[s[r]] > 0 means:
            // "We still need this character."
            //
            // If it is 0 or negative, the character is extra
            // and does not increase count.
            if(char_freq[s[r]] > 0)
                count++;


            // We have now included s[r] in our window.
            //
            // Decrease its required frequency.
            //
            // Positive -> still needed
            // 0        -> exactly enough
            // Negative -> extra occurrence
            char_freq[s[r]]--;


            // If count == m, the current window contains
            // every character required by t.
            //
            // Now we try to shrink the window from the left
            // to find the smallest possible valid window.
            while(count == m)
            {

                // Current window is valid.
                //
                // Check whether it is smaller than the best
                // valid window found so far.
                if(r - l + 1 < min_length)
                {
                    // Length of current window
                    min_length = r - l + 1;

                    // Save its starting position
                    start_index = l;
                }


                // We are going to remove s[l] from the window.
                //
                // Since this character is leaving the window,
                // increase its required frequency again.
                char_freq[s[l]]++;


                // If frequency becomes positive, it means that
                // we have removed a character that was actually
                // required.
                //
                // Therefore, the window is no longer valid and
                // we must decrease count.
                //
                // Example:
                // Required A = 1
                //
                // Before removal:
                // char_freq[A] = 0
                //
                // After removing A:
                // char_freq[A] = 1
                //
                // So we are missing one A.
                if(char_freq[s[l]] > 0)
                    count--;


                // Move the left pointer forward to shrink
                // the window.
                l++;
            }


            // Move the right pointer forward to expand the
            // window and look for the next valid window.
            r++;
        }


        // If start_index is still -1, no valid window exists.
        if(start_index == -1)
            return "";


        // Return the smallest valid substring.
        //
        // start_index -> starting position of answer
        // min_length  -> length of answer
        return s.substr(start_index, min_length);
    }
};