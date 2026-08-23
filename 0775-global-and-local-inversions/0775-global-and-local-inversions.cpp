// class Solution {
// public:

//     int count = 0;//keeps count of the global inversions

//     void Merge(vector<int> &nums, int l, int r, int mid)
//     {
//         vector<int> temp;

//         int left = l;
//         int right = mid+1;

//         while(left<=mid && right<=r)
//         {
//             if(nums[left] <= nums[right] )
//             {
//                 temp.push_back(nums[left]);
//                 left++;
//             }

//             else if(nums[right] < nums[left])
//             {
//                 count += (mid + 1) - left;

//                 temp.push_back(nums[right]);
//                 right++;
//             }
//         }

//         while(left<=mid)
//         {
//         temp.push_back(nums[left]);
//         left++;
//         }

//         while(right<=r)
//         {
//         temp.push_back(nums[right]);
//         right++;
//         }

//         for(int i=l; i<=r; i++)
//         {
//             nums[i]=temp[i-l]; //example l=3 r=8 (6 elements) so the temp will have indexes from 0 to 8-3 = 5 as there are 8-3+1 elemets i.e 6 elements
//         }
//     }

//     void MergeSort(vector<int> &nums, int l, int r)
//     {
//         if(l>=r) return ;

//         int mid = l + (r-l)/2;

//         MergeSort(nums, l,mid);
//         MergeSort(nums, mid+1,r);

//         Merge(nums, l, r, mid);

//     }

//     int count_Local_inversions(vector<int> nums)
//     {
//         int n = nums.size();

//         int count_local =0;

//         for(int i=0; i<n-1;i++)
//         {
//             if(nums[i] > nums[i+1])
//             count_local++; 
//         }

//         return count_local;
//     }
//     bool isIdealPermutation(vector<int>& nums) {
        
//         int n = nums.size();

//         int number_of_local_inversions  = count_Local_inversions(nums);

//         MergeSort(nums, 0 , n-1); //it will update the count of global inversions as it is denoted by global variable count

      
//         return count  == number_of_local_inversions;
//     }
// };


class Solution {
public:

    bool isIdealPermutation(vector<int> nums)
    {
        int n = nums.size();

        // With at most 2 elements, every possible inversion is
        // automatically a local inversion.
        if(n <= 2) return true;

        // For index i, we need to know the minimum element
        // among indices i+2, i+3, ..., n-1.
        //
        // Initially i = n-3, so the only possible non-local
        // element is nums[n-1].
        int min_right = nums[n-1];

        // We go from right to left so that min_right can be
        // maintained incrementally instead of scanning the
        // entire suffix for every i.
        for(int i = n-3; i >= 0; i--)
        {
            // If nums[i] is greater than the minimum element
            // at index i+2 or beyond, then there exists a
            // non-local global inversion.
            //
            // Such an inversion cannot be a local inversion,
            // so local inversions != global inversions.
            if(nums[i] > min_right)
                return false;

            // For the next iteration (i-1), the required suffix
            // starts from index i+1.
            //
            // Therefore add nums[i+1] into our running minimum.
            min_right = min(min_right, nums[i+1]);
        }

        // No non-local inversion was found.
        // Therefore every global inversion is local.
        return true;
    }
};