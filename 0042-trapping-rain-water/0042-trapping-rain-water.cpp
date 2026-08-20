class Solution {
public:
    int trap(vector<int>& arr) {
        
        int n = arr.size();

        int l_max =0;
        int r_max =0;

        int l=0;
        int r=n-1;

        int water = 0;

        while(l<=r)
        {
            if(l_max <= r_max)
            {
                if(l_max > arr[l])
                {
                    water += l_max - arr[l];
                }

                else
                {
                    l_max = arr[l];
                }
                l++;
            }


            else if(l_max > r_max)
            {
                if(r_max > arr[r])
                {
                    water += r_max - arr[r];
                }

                else
                {
                    r_max = arr[r];
                }
                r--;
            }
        }

        return water;
    }
};