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

            int check = (sum%k + k)%k;

            if(freq.find(check) != freq.end())
            {
                count+= freq[check];
            }

            freq[check]++;
        }

        return count;
    }
};