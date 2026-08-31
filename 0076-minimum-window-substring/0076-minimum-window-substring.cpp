class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> char_freq;

        int n = s.length();
        int m = t.length();

        int count = 0;

        int min_length = INT_MAX;
        int start_index = -1;

        int l=0, r=0;

        for(int i=0; i<m; i++)
        {
            char_freq[ t[i] ]++;
        }

        while( r< n)
        {
            if(char_freq[s[r]] > 0)
            count = count+1;

            char_freq[ s[r] ]--;

            while(count == m)
            {
                if( r-l+1 < min_length)
                {
                    min_length = r-l+1;
                    start_index = l;
                }

                char_freq[ s[l] ]++;

                if(char_freq[ s[l] ] > 0)
                count =  count-1;

                l++;
            }

            r++;
            
        }

        return (start_index == -1 )?"":s.substr( start_index, min_length);
    }
};