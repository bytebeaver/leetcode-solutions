class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();

        stack<int> st;
        vector<int> nge(n);

        // int last = nums[n-1];
       int maxi = *max_element(begin(nums), end(nums));
        // for(int i=0; i<n; i++)
        // {
        //     if(nums[i] > last)
        //     {
        //         st.push(nums[i]);
        //         break;
        //     }
        // }

        //will traverse from the back 
        for(int i=n-1; i>=0; i--)
        { 
            if(nums[i] == maxi)
            {
            nge[i] = -1;
            st.push(nums[i]);
            }

            else
            {
                while(  !st.empty() && st.top()<=nums[i] )
                st.pop();

                if(st.empty())
                {
                    for(int j=0; j<i; j++)
                    {
                        if(nums[j] > nums[i])
                        {
                        nge[i] = nums[j];
                        break;
                        }

                    }

                
                }

                else
                nge[i]= st.top();


                st.push( nums[i] );
            }
        }
    return nge;
    }
};