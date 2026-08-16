// //BRUTE FORCE:

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
//         int m = matrix.size(); //number of rows
//         int n = matrix[0].size(); // number of columns

//         int i=0, j=n-1;

//         while(i<m && j >=0)
//         {
//             if(target > matrix[i][j])
//             {
//                 //row badhani padegi
//                 i++;
//             }
//             else if(target < matrix[i][j])
//             {
//                 //column km krna padega
//                 j--;
//             }
//             else
//             {
//                 //matlb target == matrix[i][j]
//                 return true;
//             }
//         }

//         //target not found in the matrix
//         return false;

//     }
// };


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(); //number of rows
        int n = matrix[0].size(); // number of columns

       int low = 0;
       int high = m*n -1;

       while(low<=high)
       {
        int mid = low + (high-low)/2;

        if(target > matrix[mid/n][mid%n])
        low = mid+1;

        else if(target < matrix[mid/n][mid%n])
        high = mid-1;

        else if(target == matrix[mid/n][mid%n])
        return true;
       }

    return false;
    }
};