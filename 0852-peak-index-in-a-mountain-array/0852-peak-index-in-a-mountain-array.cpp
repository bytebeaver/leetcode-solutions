class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0;
        int e = arr.size()-1;
        
        int mid;
        
        while(s<=e)
        {
            mid=s +(e-s)/2;
            
           
            if(mid ==0)
            {
                if(arr[mid] > arr[mid+1])
                    return mid;
            }
            else if(mid ==arr.size()-1 )
            {
                if(arr[mid] > arr[mid-1])
                    return mid;
            }
            else if(arr[mid] >= arr[mid-1] && arr[mid] >=arr[mid+1] )
            {
                return mid;
            }
            
            if(mid==0)
                s=mid+1;
            
            if(mid == arr.size()-1)
                e=mid-1;
            
            if(mid !=0 && mid!=arr.size()-1){
            if(arr[mid]>=arr[mid-1] && arr[mid] < arr[mid+1])
                s=mid+1;
            
            else if(arr[mid]>=arr[mid+1] && arr[mid] < arr[mid-1])
                e=mid-1;
            
        }}
        return -1;
    }
        
};
