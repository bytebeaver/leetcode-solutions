//done from Videotutorial codewithMIK
//best approach 
class Solution {
public:
    int maxScore(string s) {
        // Get the length of the input string
        int n = s.length();
        
        // Initialize counters for zeros and ones
        int zeros = 0; // Count of zeros in the left substring
        int ones = 0;  // Count of ones encountered in the left substring

        // Initialize the score to the smallest possible integer
        int score = INT_MIN;

        // Traverse the string from the beginning to the second-last character
        for (int i = 0; i <= n - 2; i++) {
            //we are checking till n-2 only beacause we cannot have a empty substring : check codewithMIK video for more explanation
            // Check the current character and update the zero/one counter
            if (s[i] == '1')
                ones++;  // If the character is '1', increase the ones count
            else
                zeros++; // If the character is '0', increase the zeros count

            // Update the maximum score based on the difference
            // The score here is zeros in the left substring minus ones in the left substring
            score = max(score, zeros - ones);
        }

        // Add the count of ones in the last character to include all ones in the string
        //this step is mandatory because our loop goes only upto n-2 and there can be a 1 present at the index n-1
         if (s[n - 1] == '1')
            ones++;

        // Return the maximum score by adding the total ones in the right substring
        //as we have traversed the whole string so the ones variable will now have total ones in the string s which was originally declared to contain number of 1's in  the left substring only
        return score + ones;
    }
};



// Dry Run Examples
// Example 1: s = "011101"
// Initial Values: zeros = 0, ones = 0, score = INT_MIN.

// Iteration:
// Split at i=0:
// left = "0" (zeros=1), right = "11101 (ones=4)".
// score = 1 + 4 = 5.

// Split at i=1:
// left = "01" (zeros=1, ones=1), right = "1101 (ones=3)".
// score = 1 + 3 = 4.

// Split at i=2:
// left = "011" (zeros=1, ones=2), right = "101 (ones=2)".
// score = 1 + 2 = 3.

// Split at i=3:
// left = "0111" (zeros=1, ones=3), right = "01 (ones=1)".
// score = 1 + 1 = 2.

// Split at i=4:
// left = "01110" (zeros=2, ones=3), right = "1 (ones=1)".
// score = 2 + 1 = 3.


// Final Output: Maximum score = 5.
