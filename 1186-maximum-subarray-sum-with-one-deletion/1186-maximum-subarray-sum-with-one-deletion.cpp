// class Solution {
// public:
//     int maximumSum(vector<int>& arr) {
        
//         int n = arr.size();
//         if(n==1)
//         return arr[0];

//         int no_delete = max(arr[0]+arr[1], arr[1]);
//         int one_delete = max(arr[1], arr[0]);

//         int result = max(one_delete, no_delete);

//         for(int i=2; i<n; i++)
//         {
//             int prev_no_delete = no_delete;
//             int prev_one_delete = one_delete;

//             no_delete = max(prev_no_delete + arr[i], arr[i]);

//             one_delete = max(prev_one_delete + arr[i], prev_no_delete);

//             result = max(result, max(no_delete, one_delete) );
//         }

//     return result;
//     }
// };

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];              // single element, no deletion possible

        int no_delete = arr[0];                 // best sum ending here, no deletion used
        int one_delete = INT_MIN;                // invalid at index 0

        int result = no_delete;                  // track global answer

        for (int i = 1; i < n; i++) {
            int prev_no_delete = no_delete;      // save before overwrite
            int prev_one_delete = one_delete;

            if (i == 1)
                one_delete = max(arr[1], prev_no_delete);   // avoid using invalid one_delete[0]
            else
                one_delete = max(prev_one_delete + arr[i], prev_no_delete); 
                // extend deletion-used subarray  OR  delete arr[i] now

            no_delete = max(prev_no_delete + arr[i], arr[i]); // normal Kadane's step

            result = max({result, no_delete, one_delete});   // update global best
        }

        return result;
    }
};