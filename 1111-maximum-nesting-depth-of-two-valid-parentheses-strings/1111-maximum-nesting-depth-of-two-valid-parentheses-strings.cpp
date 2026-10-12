
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {

        int d = 0;
        vector<int> result(seq.length());

        for (int i = 0; i < seq.length(); i++) {

            if (seq[i] == '(') {

                // Entering a new nesting level.
                // Increase depth first, then assign the group
                // according to the parity of the new depth.
                d++;
                result[i] = (d % 2 == 0) ? 0 : 1;

            }
            else if (seq[i] == ')') {

                // This closing bracket belongs to the same
                // nesting level as its matching opening bracket.
                // Therefore, assign its group BEFORE decreasing d.
                result[i] = (d % 2 == 0) ? 0 : 1;
                d--;
            }
        }

        return result;
    }
};
