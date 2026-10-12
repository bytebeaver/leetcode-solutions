
class Solution {
public:
    int longestValidParentheses(string s) {

        int open = 0;
        int close = 0;
        int result = 0;

        // Left-to-right traversal:
        // Handles substrings where closing parentheses may become
        // more numerous than opening parentheses.
        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(')
                open++;
            else
                close++;

            // Too many closing parentheses means this substring
            // cannot be valid, so reset both counters.
            if (open < close) {
                open = 0;
                close = 0;
            }

            // Equal counts give a valid substring because open
            // never became smaller than close in this segment.
            else if (open == close) {
                result = max(result, open + close);
            }
        }

        // Reset counters before scanning in the opposite direction.
        open = 0;
        close = 0;

        // Right-to-left traversal:
        // Handles substrings where opening parentheses may become
        // more numerous than closing parentheses.
        for (int i = s.length() - 1; i >= 0; i--) {

            if (s[i] == '(')
                open++;
            else
                close++;

            // Too many opening parentheses means this substring
            // cannot be completed into a valid substring, so reset.
            if (open > close) {
                open = 0;
                close = 0;
            }

            // Equal counts give a valid substring when scanning
            // backward without having too many opening parentheses.
            else if (open == close) {
                result = max(result, open + close);
            }
        }

        // Return the maximum valid parentheses substring length.
        return result;
    }
};
