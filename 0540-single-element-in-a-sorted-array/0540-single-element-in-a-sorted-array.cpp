class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        if(n==1) return nums[0];  // single element hi answer hai, koi pair possible nahi

        int l = 0;
        int r = n-1;

        while(l<=r)
        {
            int mid = l + (r-l)/2;  // overflow-safe mid

            // boundary case: mid start pe hai aur right neighbor se match nahi karta
            if(mid == 0 && nums[mid] != nums[mid+1])
             return nums[mid];

            // boundary case: mid end pe hai aur left neighbor se match nahi karta
            if(mid == n-1 && nums[mid] != nums[mid-1])
            return nums[mid];

            // mid ka koi bhi neighbor match nahi kar raha -> mid hi single element hai
            if(nums[mid]!= nums[mid+1] && nums[mid]!= nums[mid-1])
            return nums[mid];
          
            if(nums[mid]== nums[mid-1])
             {
                // pair (mid-1, mid) pe mila
                // pair ke ilawa left side pr kitne elements bache
                // total kitne the mid - l + 1
                // pair ke 2 hata diye to ---- mid - l + 1 - 2 = mid - l -1
                if( (mid-l-1) % 2 == 0)
                {
                    // even bache -> single left mein nahi ho sakta -> go right
                    // pair mid-1,mid tak hai, isliye l = mid+1 hi kaafi hai
                    l = mid+1;
                }
                else if((mid-l-1)%2 == 1 )
                {
                    // odd bache -> single left mein hai
                    // pair (mid-1, mid) poora skip karo -> r = mid-2
                    r = mid-2;
                }
             }


             else if(nums[mid]== nums[mid+1])
             {
                // pair (mid, mid+1) pe mila
                // pair ke ilawa right side pr kitne elements bache
                // total kitne hain mid se r tak  r - mid + 1 
                // pair ke 2 hata diye to ---- r - mid + 1 - 2 = r -mid -1
                if( (r-mid-1) % 2 == 0)
                {
                    // even bache -> single right mein nahi ho sakta -> go left
                    r = mid -1;
                    
                }
                else if((r-mid-1)%2 == 1 )
                {
                    // odd bache -> single right mein hai
                    // pair (mid, mid+1) poora skip karo -> l = mid+2
                    l = mid+2;
                }
             }
           
        }

        return 0;
    }
};