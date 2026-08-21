class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();

        map<int, int> freq;
        freq[0] = 1;

        int sum = 0;
        int count = 0;

        for(int i=0; i<n ; i++)
        {
            sum += nums[i];

            // int remainder= (sum%k + k)%k;   OR do it like:
            
            int remainder = sum % k;

            if(remainder < 0)
            remainder +=k;

            if(freq.find(remainder) != freq.end())
            {
                count+= freq[remainder];
            }

            freq[remainder]++;
        }

        return count;
    }
};