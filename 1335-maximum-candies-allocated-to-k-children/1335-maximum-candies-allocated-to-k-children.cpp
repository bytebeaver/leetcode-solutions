// class Solution {
// public:
//     int maximumCandies(vector<int>& candies, long long k)
// {
//         long long temp1=k;
//         int max_c =0;

//         for(int i=0; i<candies.size();i++)
//             {
//                 max_c=max(max_c, candies[i]);
//             }

//         while(max_c >0)
//         {
//             for(int i=0;i<candies.size();i++)
//             {
//                 long long temp = candies[i]/max_c;
//                 temp1 -=temp;
//             }

//             if(temp1<=0)
//             {
//                 return max_c;
//             }
        
//         temp1=k;
//         max_c--;
//         }

// return 0;
// }
// };

class Solution {
public:
    bool check(vector<int>& candies, long long k, long long mid) {
        long long split = 0;
        for(int i = 0; i < candies.size(); ++i) {
            split += candies[i]/mid;
        }   
        return split>=k;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for(int i = 0; i < candies.size(); ++i) {
            sum += candies[i];
        }
        
        long long start = 1, end = sum;
        long long ans = 0;
        
        while(start <= end) {
            long long mid = (start + end)/2;
            if(check(candies, k, mid)) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid-1;
            }
        }
        return ans;
    }
};

