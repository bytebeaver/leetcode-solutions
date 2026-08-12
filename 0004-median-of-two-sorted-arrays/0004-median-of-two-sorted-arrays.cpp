class Solution {
 public:

 vector<int> merge(vector<int> nums1, vector<int> nums2)
 {
    int i=0,j=0;
    int n = nums1.size();
    int m = nums2.size();
    vector<int> merged(m+n);

    int idx=0;
    while(i<n && j<m)
    {
        if(nums1[i] <= nums2[j])
        {
        merged[idx] = nums1[i];
        idx++;
        i++;
        }

        else if(nums1[i] > nums2[j])
        {
            merged[idx] = nums2[j];
        idx++;
        j++;
        }
    }

    while(i<n){
         merged[idx] = nums1[i];
        idx++;
        i++;
    }

     while(j<m){
         merged[idx] = nums2[j];
        idx++;
        j++;
    }

    return merged;
 }
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
    vector<int> Merge = merge(nums1 , nums2);

    int size = Merge.size();
    
    if(size%2 !=0)
    {
        return (double)Merge[size/2];
    }

    else
    {
        return (double)(Merge [size/2] + Merge[size/2 -1])/2;
    }

    return 0;
  }
};