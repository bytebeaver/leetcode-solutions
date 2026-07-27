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
        if (n == 1)
            return arr[0];

        int no_delete = arr[0];
        int one_delete = INT_MIN;

        int result = max(no_delete, one_delete);

        for (int i = 1; i < n; i++)
        {
            int prev_no_delete = no_delete;
            int prev_one_delete = one_delete;

            if (i == 1)
            {
                one_delete = max(prev_one_delete, prev_no_delete);   // max(arr[1], arr[0])
            }
            else
            {
                one_delete = max(prev_one_delete + arr[i], prev_no_delete);
            }

            no_delete = max(prev_no_delete + arr[i], arr[i]);

            result = max(result, max(no_delete, one_delete));
        }

        return result;
    }
};