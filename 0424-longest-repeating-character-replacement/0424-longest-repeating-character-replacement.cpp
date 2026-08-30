class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.length();

        vector<int> char_freq(26, 0);

        int max_freq = 0;

        int max_len = 0;

        int l=0,r=0;

        while(r<n)
        {
            char_freq[ s[r] - 'A' ]++;

            max_freq = max( max_freq, char_freq[ s[r] - 'A']);

            //check if segment is valid or not
            
            while( (r-l+1) - max_freq > k) //i.e number of  conversions required is more than k
            {
                //we have to increment l so we will decrement the freq of character at current l
                char_freq[ s[l]- 'A' ]--;

                //recalculate the max_freq
                max_freq = 0;

                for(int i=0; i<26; i++) 
                max_freq = max(max_freq, char_freq[i]);

                l++;

            }

            if( (r-l+1) - max_freq <= k)
            {
                max_len = max(max_len, r-l+1);
            }

            r++;
        }

        return max_len;
    }
};