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
        
        int m = matrix.size(); // total rows
        int n = matrix[0].size(); // total columns (assuming non-empty matrix)

        // Treat the whole matrix as a single sorted 1D array of size m*n
        int low = 0;
        int high = m*n - 1;

        while(low <= high) // standard binary search invariant: search space non-empty
        {
            int mid = low + (high-low)/2; // overflow-safe mid

            // Map the 1D virtual index 'mid' back to 2D coordinates:
            // mid/n gives row number, mid%n gives column number
            if(target > matrix[mid/n][mid%n])
                low = mid+1;   // target lies in the right half, discard left half

            else if(target < matrix[mid/n][mid%n])
                high = mid-1;  // target lies in the left half, discard right half

            else if(target == matrix[mid/n][mid%n])
                return true;   // found target
        }

        return false; // search space exhausted, target not present
    }
};