class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length(); // The length of the strings is the same.

        int i = 0; // Pointer for `start` string.
        int j = 0; // Pointer for `target` string.

        // Loop until both pointers reach the end of their respective strings.
        while (i < n || j < n) {
            // Move pointer `i` to the next non-underscore ('_') character in `start`.
            while (i < n && start[i] == '_') {
                i++;
            }

            // Move pointer `j` to the next non-underscore ('_') character in `target`.
            while (j < n && target[j] == '_') {
                j++;
            }

            // If either pointer reaches the end of its string, both must reach the end for valid transformation.
            if (i == n || j == n) {
                return i == n && j == n; // Both pointers must reach the end together.
            }

            // If the characters at `i` and `j` are not the same, the transformation is invalid.
            if (start[i] != target[j]) {
                return false;
            }

            // If the current character is 'L':
            // It must not move to the right (i.e., `i` must be >= `j`).
            if (start[i] == 'L' && i < j) {
                return false; // 'L' cannot move to the right.
            }

            // If the current character is 'R':
            // It must not move to the left (i.e., `i` must be <= `j`).
            if (start[i] == 'R' && i > j) {
                return false; // 'R' cannot move to the left.
            }

            // If no rule is violated, move both pointers to the next character.
            i++;
            j++;
        }

        // If we successfully processed all characters, the transformation is valid.
        return true;
    }
};

/*
Example Run-Through:
Input: start = "_L__R__R_", target = "L______RR"
Output: true

1. Initial values:
   - start = "_L__R__R_", target = "L______RR", i = 0, j = 0.

2. Step 1:
   - Move `i` to the first non-underscore in `start`: i = 1 (points to 'L').
   - Move `j` to the first non-underscore in `target`: j = 0 (points to 'L').
   - Both characters are 'L', and i >= j. Valid move.
   - Move both pointers: i = 2, j = 1.

3. Step 2:
   - Move `i` to the next non-underscore: i = 4 (points to 'R').
   - Move `j` to the next non-underscore: j = 7 (points to 'R').
   - Both characters are 'R', and i <= j. Valid move.
   - Move both pointers: i = 5, j = 8.

4. Step 3:
   - Move `i` to the next non-underscore: i = 7 (points to 'R').
   - `j` remains at 8 (points to 'R').
   - Both characters are 'R', and i <= j. Valid move.
   - Move both pointers: i = 8, j = 9.

5. Step 4:
   - Both pointers are at the end of their respective strings: i = n, j = n.
   - The transformation is valid.

Output: true
*/
