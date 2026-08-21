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


