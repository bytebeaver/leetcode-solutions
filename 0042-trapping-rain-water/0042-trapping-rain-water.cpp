class Solution {
public:
    int trap(vector<int>& arr) {
        
        int n = arr.size();

        int l_max = 0;   // left side ka ab tak ka max height (left wall)
        int r_max = 0;   // right side ka ab tak ka max height (right wall)

        int l = 0;       // left pointer, array ke start se
        int r = n - 1;    // right pointer, array ke end se

        int water = 0;   // total trapped water accumulate karega

        while (l <= r)   // jab tak dono pointers cross na ho jayein
        {
            if (l_max <= r_max)
            {
                // left side "weaker" hai, isliye left index ka answer
                // ab finalize kiya ja sakta hai (right mein utna hi ya usse bada wall hai)
                if (l_max > arr[l])
                {
                    // current bar se lambi wall left mein pehle dekh chuke hain
                    // → is bar par paani ruk sakta hai
                    water += l_max - arr[l];
                }
                else
                {
                    // current bar hi ab tak ki sabse badi left wall hai
                    l_max = arr[l];
                }
                l++;   // left pointer aage badhao
            }

            else if (l_max > r_max)
            {
                // right side "weaker" hai, similarly process karo
                if (r_max > arr[r])
                {
                    water += r_max - arr[r];
                }
                else
                {
                    r_max = arr[r];
                }
                r--;   // right pointer peeche laao
            }
        }

        return water;
    }
};

//STACK SOLUTION :::::
// class Solution {
// public:
//     int trap(vector<int>& arr) {

//         int n = arr.size();

//         // Stack stores indices of bars.
//         // Heights corresponding to these indices
//         // are maintained in decreasing order.
//         stack<int> st;

//         int water = 0;

//         for (int i = 0; i < n; i++) {

//             // Current bar arr[i] is taller than the bar
//             // at the top of the stack.
//             //
//             // Therefore, arr[i] can act as the RIGHT boundary
//             // for the valley represented by st.top().
//             while (!st.empty() && arr[i] > arr[st.top()]) {

//                 // This is the bottom of the valley.
//                 int bottom = st.top();
//                 st.pop();

//                 // If there is no bar on the left,
//                 // we cannot trap any water.
//                 if (st.empty())
//                     break;

//                 // The new stack top is the LEFT boundary.
//                 int left = st.top();

//                 // Current index i is the RIGHT boundary.
//                 int right = i;

//                 // Width of the trapped region.
//                 //
//                 // left and right themselves are walls,
//                 // so only the indices between them contain water.
//                 int width = right - left - 1;

//                 // Height of water is determined by
//                 // the smaller of the two boundary walls.
//                 int height =
//                     min(arr[left], arr[right]) - arr[bottom];

//                 // Add trapped water.
//                 water += width * height;
//             }

//             // Add current index to stack.
//             st.push(i);
//         }

//         return water;
//     }
// };