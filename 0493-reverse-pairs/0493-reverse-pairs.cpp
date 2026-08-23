
class Solution {
public:

    // Stores the total number of inversions found during all merges.
    // long long is safer because the number of inversions can be n(n-1)/2.
    long long count = 0;

    void merge(vector<int>& arr, int l, int mid, int r)
    {
        vector<int> temp;

        // Points to the current element in the sorted left half.
        int left = l;

        // Points to the current element in the sorted right half.
        int right = mid + 1;

        //counting the reverse pairs:

        int j = mid+1;

        for(int i = l ; i<= mid; i++)
        {
           while(j <=r && arr[i] > 2LL*arr[j])
           {
            j++;
           }

           count += j-(mid+1); //here mid+1 denotes the starting index of the right array (mid+1...r)
        }

        // Both halves are already sorted.
        // This sorted property lets us count multiple inversions at once.
        while (left <= mid && right <= r)
        {

          
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
        
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // Remaining left elements are already sorted.
        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        // Remaining right elements are already sorted.
        while (right <= r)
        {
            temp.push_back(arr[right]);
            right++;
        }

        // Copy the merged sorted range back into arr.
        for (int i = l; i <= r; i++)
        {
            arr[i] = temp[i - l];
        }
    }

    void mergeSort(vector<int>& arr, int l, int r)
    {
        // 0 or 1 element means no possible inversion.
        if (l >= r)
            return;

        // Split the array into two halves.
        int mid = l + (r - l) / 2;

        // Sort the left half.
        mergeSort(arr, l, mid);

        // Sort the right half.
        mergeSort(arr, mid + 1, r);

        // Merge the two sorted halves and count cross-half inversions.
        merge(arr, l, mid, r);
    }

    int reversePairs(vector<int> &arr)
    {
        // Reset in case the same Solution object is reused.
        count = 0;

        int n = arr.size();

        // Sort the array while counting inversions.
        mergeSort(arr, 0, n - 1);

        return count;
    }
};


