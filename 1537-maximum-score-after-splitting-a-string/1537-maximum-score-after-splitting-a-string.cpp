class Solution {
public:
    int maxScore(string s) {
        
        int n = s.length();
        
        int zeros=0;
        int ones=0;

        int score = INT_MIN;

        for(int i=0; i<=n-2; i++){
            
            if(s[i]=='1')
            ones++;

            else
            zeros++;

            score = max(score, zeros-ones);
        }

        if(s[n-1]=='1')
        ones++;

        return score+ones;
    }
};