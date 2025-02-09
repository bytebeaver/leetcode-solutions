//code story with MIK

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        int n = nums.size();
        long long result = 0;
        for(int i=0; i<n ; i++)
        {
            nums[i]= nums[i]-i;
        }

        unordered_map<int, int> mp;
         mp[ nums[0] ] = 1;

         for(int j=1; j<n ; j++)
         {
            int count_of_nums_j = mp[ nums[j] ]; //yaha se pehle j kitni baar dekha hai

            int total_nums_before_j = j ; //yaha se pehle kitne nums travese ho chuke

            int bad_pairs = total_nums_before_j - count_of_nums_j;
            
            result += bad_pairs;

            mp[ nums[j] ]++;

         }

         return result;
    }
};