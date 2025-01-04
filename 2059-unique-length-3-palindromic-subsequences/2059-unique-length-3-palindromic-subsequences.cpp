// codewithMIK tutorial


// Intuition Rephrased
// The goal is to find all unique 3-letter palindromic subsequences in a string. A 3-letter palindrome has the structure char _ char, where:

// The first and last characters are the same (let's call it char).
// The middle character can be any valid character that appears between the first and last occurrences of char.
// Thus, for a given character char in the string:

// You look for its first occurrence (leftmost position) and last occurrence (rightmost position).
// Between these two positions, any unique character can serve as the middle character, forming a valid 3-letter palindrome with the structure char _ char.

// For example, in the string aabca:

// For the character 'a':
// First occurrence: index 0.
// Last occurrence: index 4.
// Unique characters between these indices are {a, b, c}.
// This forms the palindromes: "aaa", "aba", "aca".
// If the first and last occurrences of a character are the same (e.g., the character appears only once or there are no valid middle characters), it cannot form a 3-letter palindrome, and we skip it.


// How Your Intuition Relates to Your Solution:
// Identifying the first and last occurrence:

// In your solution, you loop through the string to find the leftmost (left_index) and rightmost (right_index) occurrences of each character.
// This directly implements your idea of determining the two endpoints (char and char) of the palindrome.
// Finding unique middle characters:

// Between these endpoints, you use a set to collect all unique characters (st).
// This implements your intuition that any character between the endpoints can act as the middle character to complete the char _ char palindrome structure.
// Counting unique palindromes:

// For each character, the size of the set (st.size()) represents the number of valid palindromes that can be formed with that character as the first and last character.
// Adding this to the result aligns with your understanding that we are counting all unique char _ char palindromes.


// Final Rephrased Intuition:

// To count all unique 3-letter palindromic subsequences, focus on their structure:

// Each palindrome has the form char _ char.
// For every unique character char in the string:
// Determine its first and last occurrences.
// The characters between these indices can act as valid middle characters to form a palindrome.
// Count all unique middle characters for every character, as they correspond to unique palindromes.
// If a character does not appear at least twice, or if there are no valid middle characters, it cannot form a palindrome.
// By systematically applying this logic to all unique characters, we can count all valid palindromes efficiently and accurately.







class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length(); // Length of the string, n = 5 for "aabca"

        // A set to store all unique letters in the string
        unordered_set<char> letters;

        // Step 1: Collect all unique letters in the string
        for (int i = 0; i < n; i++) {
            letters.insert(s[i]); // Adds 'a', 'b', 'c' to the set
        }
        // letters = {'a', 'b', 'c'}

        int result = 0; // Initialize result to count the unique palindromic subsequences

        // Step 2: Process each unique letter in the set
        for (char letter : letters) {
            int left_index = -1, right_index = -1; // Initialize indices for the letter

            // Find the leftmost and rightmost occurrences of the letter
            for (int i = 0; i < n; i++) {
                if (s[i] == letter) {
                    if (left_index == -1) left_index = i; // Set leftmost occurrence
                    right_index = i;                     // Update rightmost occurrence
                }
            }

            // Example: For letter 'a'
            // - First occurrence: left_index = 0
            // - Last occurrence: right_index = 4

            // Skip if the letter occurs only once or has no valid middle section
            if (left_index == right_index) continue;

            // Step 3: Identify unique characters between left and right indices
            unordered_set<char> st; // To store unique middle characters

            for (int middle = left_index + 1; middle <= right_index - 1; middle++) {
                st.insert(s[middle]); // Add characters between indices
            }

            // Example for 'a':
            // - Characters between indices 0 and 4: {'a', 'b', 'c'}
            // - Unique palindromes: "aaa", "aba", "aca"

            result += st.size(); // Add the count of unique middle characters

            // Example for 'a': st.size() = 3, result = 3
        }

        // Step 4: Repeat for remaining letters ('b' and 'c')

        // Processing 'b':
        // - First occurrence: left_index = 1
        // - Last occurrence: right_index = 3
        // - Characters between indices 1 and 3: {'a'}
        // - Unique palindrome: "bab"
        // - Add 1 to result, result = 3 + 1 = 4

        // Processing 'c':
        // - First occurrence: left_index = 2
        // - Last occurrence: right_index = 2
        // - No valid middle section, so skip

        return result; // Final result = 4
    }
};

/*
Detailed Example Walkthrough for s = "aabca":
-------------------------------------------------
Step 1: Unique letters in the string -> {'a', 'b', 'c'}

Step 2: Process each letter:
  - For 'a':
      - left_index = 0, right_index = 4
      - Middle characters = {'a', 'b', 'c'}
      - Palindromic subsequences = "aaa", "aba", "aca"
      - Add 3 to result, result = 3
  - For 'b':
      - left_index = 1, right_index = 3
      - Middle characters = {'a'}
      - Palindromic subsequences = "bab"
      - Add 1 to result, result = 4
  - For 'c':
      - left_index = 2, right_index = 2
      - No valid middle characters, skip.

Final Result: 4 unique palindromic subsequences of length 3.
*/