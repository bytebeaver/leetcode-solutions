class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int count = 0;

        int n = s.length();

        int l=0, r=0;
        vector<int> char_freq(3,0);
        while(r<n)
        {
            if(s[r] == 'a')
            char_freq[0]++;

            else if(s[r] == 'b')
            char_freq[1]++;

            else if(s[r] == 'c')
            char_freq[2]++;

            while(char_freq[0] >=1 && char_freq[1] >=1 && char_freq[2] >=1)
            {
                count += n-r;
                
                char_freq[s[l] - 'a']--;

                l++;

                
            }

            r++;

        }

        return count;
    }
};