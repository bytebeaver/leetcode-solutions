class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();  // all letters are distinct, so n = number of distinct letters
        int totalPushes = 0;
        
        for (int i = 0; i < n; i++) {
            totalPushes += (i / 8) + 1;
        }
        
        return totalPushes;
    }
};