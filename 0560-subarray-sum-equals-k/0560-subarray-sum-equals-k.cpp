// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
        
//         int count = 0;
        
//         for(int i=0; i<nums.size(); i++)
//         {
//             int sum=0;
//             for(int j=i; j<nums.size(); j++)
//             {
//                 sum += nums[j];

//                 if(sum == k)
//                 count++;

//             }
//         }

//         return count;
//     }
// };


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       
       int sum = 0;
       int count = 0;

       map<int, int> freq;
        freq[0] = 1;

       for(int i=0; i< nums.size(); i++)
       {
          sum += nums[i];

          int partial = sum -k;

          if( freq[partial])
          count += freq[partial];

          freq[sum]++;

       }

       return count;
       
    }
};