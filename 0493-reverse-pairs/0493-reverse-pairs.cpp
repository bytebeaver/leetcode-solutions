class Solution {
public:
    // Stores total inversions; long long because count can exceed INT_MAX for n=5*10^4.
    long long count = 0;

    void merge(vector<int>& arr, int l, int mid, int r)
    {
        vector<int> temp;
        int left = l;      // pointer for merging (left half)
        int right = mid + 1; // pointer for merging (right half)

        // ---- COUNTING PHASE ----
        // j never resets across i iterations — this is what makes it O(n) not O(n^2).
        int j = mid + 1;
        for (int i = l; i <= mid; i++)
        {
            // Both halves sorted => threshold moves monotonically forward => j only advances.
            while (j <= r && arr[i] > 2LL * arr[j]) // 2LL avoids overflow
            {
                j++;
            }
            // [mid+1, j-1] are all valid reverse-pair partners for arr[i].
            count += j - (mid + 1);
        }

        // ---- STANDARD MERGE PHASE ----
        while (left <= mid && right <= r)
        {
            if (arr[left] <= arr[right]) { temp.push_back(arr[left]); left++; }
            else { temp.push_back(arr[right]); right++; }
        }
        while (left <= mid) { temp.push_back(arr[left]); left++; }
        while (right <= r) { temp.push_back(arr[right]); right++; }

        for (int i = l; i <= r; i++) arr[i] = temp[i - l];
    }

    void mergeSort(vector<int>& arr, int l, int r)
    {
        if (l >= r) return; // 0/1 element, no pair possible
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r); // count cross-half pairs + merge
    }

    int reversePairs(vector<int> &arr)
    {
        count = 0; // reset for reuse
        int n = arr.size();
        mergeSort(arr, 0, n - 1);
        return count;
    }
};