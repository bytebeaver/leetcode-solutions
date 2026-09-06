//OPTIMAL APPROACH USING 2 stacks
class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {

        int n = nums.size();

        // Initially every answer is -1.
        // If we never find the second greater,
        // it will remain -1.
        vector<int> ans(n, -1);

        // st1:
        // Stores INDEXES of elements waiting for
        // their FIRST greater element.
        stack<int> st1;

        // st2:
        // Stores INDEXES of elements that have already
        // found their FIRST greater and are waiting for
        // their SECOND greater element.
        stack<int> st2;


        // Process the array from left to right.
        for(int i = 0; i < n; i++)
        {

            // Temporary vector.
            // It stores the indexes removed from st1
            // during this iteration.
            //
            // We use it to preserve their ordering
            // while transferring them to st2.
            vector<int> moved;


            // ------------------------------------------------
            // STEP 1:
            // Find SECOND GREATER elements.
            // ------------------------------------------------

            while(!st2.empty() && nums[i] > nums[st2.top()])
            {
                // st2.top() gives an INDEX.
                //
                // nums[st2.top()] gives the VALUE at that index.
                //
                // Since nums[i] is greater than that value,
                // nums[i] is its SECOND GREATER element.

                ans[st2.top()] = nums[i];

                // Its second greater has been found,
                // so remove its index from st2.
                st2.pop();
            }


            // ------------------------------------------------
            // STEP 2:
            // Find FIRST GREATER elements.
            // ------------------------------------------------

            while(!st1.empty() && nums[i] > nums[st1.top()])
            {
                // nums[i] is the FIRST GREATER element
                // for the element at st1.top().

                // Save the INDEX temporarily.
                moved.push_back(st1.top());

                // Remove it from st1 because
                // its first greater has been found.
                st1.pop();
            }


            // ------------------------------------------------
            // STEP 3:
            // Current element waits for its FIRST GREATER.
            // ------------------------------------------------

            st1.push(i);


            // ------------------------------------------------
            // STEP 4:
            // Elements that found their first greater
            // now wait for their SECOND GREATER.
            //
            // Reverse the order while pushing so that
            // the original ordering is preserved.
            // ------------------------------------------------

            for(int j = moved.size() - 1; j >= 0; j--)
            {
                st2.push(moved[j]);
            }
        }

        return ans;
    }
};



//another approach that goes n square but is really good concept
// class Solution {
// public:

//     vector<int> secondGreaterElement(vector<int>& nums) {

//         int n = nums.size();

//         // Answer for every index.
//         // Initially assume second greater doesn't exist.
//         vector<int> ans(n, -1);

//         // nge_idx[i] = index of the first greater element
//         // to the right of i.
//         vector<int> nge_idx(n);

//         // Stack stores indexes.
//         stack<int> st;


//         // =========================================================
//         // PHASE 1:
//         // Find the NGE index for every element
//         // =========================================================

//         for(int i = n - 1; i >= 0; i--)
//         {

//             // Remove all elements that are <= nums[i].
//             // They cannot be the first greater element of nums[i].
//             while(!st.empty() && nums[st.top()] <= nums[i])
//             {
//                 st.pop();
//             }


//             // If stack is empty, there is no greater element
//             // to the right.
//             //
//             // We use n as a sentinel instead of -1 because
//             // later we do:
//             //
//             // l = nge_idx[i] + 1
//             //
//             // If nge_idx[i] = n:
//             // l = n + 1
//             // which is safely outside the array.
//             if(st.empty())
//             {
//                 nge_idx[i] = n;
//             }

//             else
//             {
//                 // st.top() is an INDEX.
//                 // nums[st.top()] is the VALUE.
//                 nge_idx[i] = st.top();
//             }


//             // Current index becomes a candidate NGE
//             // for elements to its left.
//             st.push(i);
//         }


//         // =========================================================
//         // PHASE 2:
//         // Find the SECOND greater element
//         // using NGE jumps.
//         // =========================================================

//         for(int i = 0; i < n; i++)
//         {

//             // First greater of nums[i] is at nge_idx[i].
//             //
//             // The second greater must be AFTER that element.
//             // Therefore start from:
//             //
//             // nge_idx[i] + 1
//             int l = nge_idx[i] + 1;


//             while(l < n && nums[l] <= nums[i])
//             {

//                 // nums[l] is NOT greater than nums[i].
//                 //
//                 // Instead of checking l+1, l+2, l+3...
//                 // individually, jump directly to the NGE
//                 // of nums[l].
//                 //
//                 // Why is this safe?
//                 //
//                 // Between l and nge_idx[l], every element
//                 // is <= nums[l].
//                 //
//                 // And we already know:
//                 //
//                 // nums[l] <= nums[i]
//                 //
//                 // Therefore all elements between l and
//                 // nge_idx[l] are also <= nums[i].
//                 //
//                 // So none of them can be our second greater.
//                 l = nge_idx[l];
//             }


//             // We went outside the array.
//             // Therefore second greater does not exist.
//             if(l >= n)
//             {
//                 ans[i] = -1;
//             }

//             else
//             {
//                 // nums[l] is the second greater element.
//                 ans[i] = nums[l];
//             }
//         }


//         return ans;
//     }
// };