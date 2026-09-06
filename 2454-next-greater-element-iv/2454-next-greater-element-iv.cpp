// class Solution {
// public:
//     vector<int> secondGreaterElement(vector<int>& nums) {
        
//         int n = nums.size();

//         vector<int> nge_idx( n);

//         vector<int> ans(n);

//         stack<int> st;

//         for(int i=n-1; i>=0; i--)
//         {
//             while( !st.empty() && nums[st.top()] <= nums[i] )
//             st.pop();

//             if( st.empty())
//             nge_idx[i] = n ; //why we are taking n here and not -1??? --- cuz in the later part of the code the l pointer will take value of nge_idx and that cannot be -1 ..we will see
            

//             else 
//             {
//                 nge_idx[i] = st.top();
//             }

//             st.push(i);
//         }

//         for( int i=0; i<n ; i++)
//         {
//             int l = nge_idx[i] + 1;

//             while( l < n && nums[l] <= nums[i])
//             l = nge_idx[l];

//             if( l>=n)
//             ans[i] = -1;

//             else
//             ans[i] = nums[l];
//         }

//         return ans;
//     }
// };



class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> ans(n, -1);

        stack<int> st1;
        stack<int> st2;


        for(int i=0; i<n; i++)
        {
            
           vector<int> moved;
           while( !st2.empty() && nums[i] > nums[st2.top()])
           {
            //nums[st2.top()] has found its second greater element 
            ans[st2.top()] = nums[i];

            //pop it from stack 2
            st2.pop();
           }


           while( !st1.empty() && nums[i] > nums[st1.top()])
           {
            //nums[st1.top()] has found its first greater element 
            //move it to moved vector
            moved.push_back( st1.top() );

            //pop from st1
            st1.pop();
           }

           //push the current i in stack 1
            st1.push(i);

            //transfer elements from moved vector to stack 2 because they are waiting for their second greater 

            for( int j= moved.size()-1; j>=0; j--)
            {
                st2.push( moved[j] );
            }
            
        }
        return ans;
    }
};