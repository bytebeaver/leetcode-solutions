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

    int isIdealPermutation(vector<int> nums)
    {
        int n = nums.size();

        if(n<=2) return true;

        
        int min_right = nums[n-1];

        for(int i=n-3; i>=0; i--)
        {
            if(nums[i] > min_right)
            return false;

            min_right = min(min_right, nums[i+1]);
        }

    return true;
        
    }
    };
