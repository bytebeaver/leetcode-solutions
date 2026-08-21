class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        int diff = 0;

        map<int, int> freq;
        freq[0] = -1;
        
        int c1 = 0; //count number of 1s till index i
        int c0 = 0; //count number of 0s till index i

        int length = 0;

        for(int i=0; i<n ; i++)
        {
            (nums[i]==1)?c1++:c0++;

             diff = c1 - c0;
              
              if(freq.find(diff) != freq.end())
              {
                length = max(length , i - freq[diff]);
              }

              else if(freq.find(diff) == freq.end())
              freq[diff] = i;


              
            
        }

    return length;
    }
};