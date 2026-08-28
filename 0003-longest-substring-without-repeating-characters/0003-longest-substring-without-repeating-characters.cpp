class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // Store the length of the string
        int n = s.length();

        // map stores:
        // character -> its latest index in the string
        //
        // Example:
        // a -> 3
        // b -> 4
        // c -> 5
        map<char, int> mp;

        // If the string is empty,
        // there is no substring.
        if(n == 0) return 0;

        // l represents the left boundary
        // of our current sliding window.
        int l = 0;

        // Initially, the first character is our window.
        // Store its index in the map.
        mp[s[l]] = l;

        // r represents the right boundary.
        // Start from the second character because
        // the first character is already processed.
        int r = l + 1;

        // Initially our window contains one character,
        // so the maximum length is 1.
        int maxlength = 1;

        // Process the remaining characters one by one.
        while(r < n)
        {
            /*
                Check whether s[r] is NOT present
                inside the current window.

                There are two possibilities:

                1. Character does not exist in the map:

                   mp.find(s[r]) == mp.end()

                2. Character exists, but its previous
                   occurrence is before l.

                   mp[s[r]] < l

                   In that case, the previous occurrence
                   is outside our current window, so it
                   does not create a duplicate.
            */
            if( mp.find(s[r]) == mp.end() || mp[s[r]] < l)
            {
                // s[r] can safely be added to the window.

                // Current window is from l to r.
                //
                // Number of elements:
                // r - l + 1
                int length = r - l + 1;

                // Update the maximum substring length.
                maxlength = max(maxlength, length);
            }

            /*
                Otherwise, s[r] already exists inside
                the current window.

                This means:

                    mp[s[r]] >= l

                So we have found a duplicate.
            */
            else if( mp[s[r]] >= l)
            {
                /*
                    Move l just after the previous occurrence
                    of s[r].

                    Example:

                    a b c a
                    ↑     ↑
                    old   r
                    l

                    Previous 'a' is at index 0.

                    Therefore:

                    l = 0 + 1 = 1

                    New window:

                    a b c a
                      ↑   ↑
                      l   r
                */
                l = mp[s[r]] + 1;

                // Calculate the length of the new valid window.
                int length = r - l + 1;

                // Update the maximum length.
                maxlength = max(maxlength, length);
            }

            /*
                IMPORTANT:

                Store the CURRENT occurrence as the latest
                occurrence of this character.

                This is necessary because future duplicates
                should use the most recent index.

                Example:

                If we had:

                a -> 0

                and now we encounter another 'a' at index 3,

                we update:

                a -> 3
            */
            mp[s[r]] = r;

            // Move the right pointer to the next character.
            r++;
        }

        // Return the maximum length found.
        return maxlength;
    }
};