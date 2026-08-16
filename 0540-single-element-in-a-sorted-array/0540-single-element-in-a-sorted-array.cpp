class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        if(n==1) return nums[0];

        int l = 0;
        int r = n-1;

        while(l<=r)
        {
            int mid = l + (r-l)/2;

            if(mid == 0 && nums[mid] != nums[mid+1])
             return nums[mid];

            if(mid == n-1 && nums[mid] != nums[mid-1])
            return nums[mid];

            if(nums[mid]!= nums[mid+1] && nums[mid]!= nums[mid-1])
            return nums[mid];
            
            if(l==mid)
            return nums[r];
            
            if(nums[mid]== nums[mid-1])
             {
                //pair ke ilawa left side pr kitne elements bache
                //total kitne the mid - l + 1
                //pair ke 2 hata diye to ---- mid - l + 1 - 2 = mid - l -1
                if( (mid-l-1) % 2 == 0)
                {
                    //agar pair ko hata ke  even elements bache hai to yaha pr single element nahi ho sakta
                    //go right 
                    l = mid+1;
                }
                else if((mid-l-1)%2 == 1 )
                {
                    r = mid-2;
                }
             }


             else if(nums[mid]== nums[mid+1])
             {
                //pair ke ilawa left side pr kitne elements bache
                //total kitne hain mid se r tak  r - mid + 1 
                //pair ke 2 hata diye to ---- r - mid + 1 - 2 = r -mid -1
                if( (r-mid-1) % 2 == 0)
                {
                    //agar pair ko hata ke  even elements bache hai to yaha pr single element nahi ho sakta
                    //go left
                    r = mid -1;
                    
                }
                else if((r-mid-1)%2 == 1 )
                {
                    l = mid+2;
                }
             }
           
        }

        return 0;
    }
};