class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();

        map<char, int> mp;

        if(n==0) return 0;
        int l=0;
        mp[s[l]] = l;

        int r=l+1;
        int maxlength = 1;
        while(r<n)
        {
            if( mp.find(s[r]) == mp.end() || mp[ s[r] ] <l)
            {
                int length = r-l+1;
                maxlength = max(maxlength, length);
            }

            else if( mp[s[r]] >= l)  // matlab agr mp[s[r]] exist krta hai and l ya uske right me hai to l ko update krdo
            {

                l=mp[s[r]]+1;
                int length = r-l+1;
                maxlength = max(maxlength, length);
            }

            mp[s[r]] = r;
            r++;
        }

        return maxlength;
    }
};