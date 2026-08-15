// class Solution {
// public:
//     int minDays(vector<int>& bloomDay, int m, int k) {
        

//         //brute force
//         // vector<int> sorted =  sort(bloomDay.begin(), bloomDay.end());
//         int min_days = INT_MAX;

//         if((long long) m*k > bloomDay.size())
//         return -1;

//         for(int i =0 ; i< bloomDay.size(); i++)
//         {
//             int day = bloomDay[i];

//             vector<bool> temp(bloomDay.size(), false);

//             for(int i = 0; i<bloomDay.size(); i++)
//             {
//                 if(bloomDay[i] <= day)
//                 {
//                     temp[i] = true;
//                 }
//             }


//             int counter = 0;
//             int j =0;
//             int target = m;
//             while(target > 0 && j < temp.size())
//             {
//                 if(temp[j] == true)
//                 {
//                     counter++;
//                     if(counter == k)
//                     {
//                        target--;
//                        counter =0;
//                     }
//                     j++;
//                 }

//                 else if(temp[j] == false)
//                 {
//                     counter = 0;
//                     j++;
//                 }
//             }

//             if(target == 0)
//             {
//                 min_days = min(min_days, day);
//             }

//         }

//     return min_days;
//     }
// };


class Solution {
public:

    bool possible(int waiting_days, vector<int> bloomDay, int m, int k)
    {
        // counter track karta hai consecutive (adjacent) khile hue flowers ki count
        // adjacency zaroori hai kyunki bouquet ke liye flowers ek saath hone chahiye
        int counter = 0;

        for(auto& it : bloomDay)
        {
            if(it <= waiting_days)   
            // <= isliye kyunki flower jo pehle bhi khil chuka hai (bloomDay < waiting_days)
            // wo bhi ab tak available hai, sirf == wale din khila flower nahi
            {
                counter++;
                if(counter == k)
                {   
                    // k consecutive flowers mil gaye -> ek bouquet complete
                    counter = 0;   // reset karo agla bouquet count karne ke liye
                    m--;
                    
                    if(m == 0)
                    return true;   
                    // IMPORTANT FIX: jaise hi required m bouquets ban jaayein, turant true return karo
                    // isse m negative nahi hoga agar aur bhi extra bouquets ban sakte the
                }
            }

            else if(it > waiting_days)
            {
                // ye flower abhi nahi khila -> adjacency chain toot gayi
                counter = 0;
            }
        }

        // loop poora chal gaya lekin m abhi bhi 0 nahi hua -> is din tak possible nahi
        return false;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int l = 1;  // minimum ek din to wait karna hi padega (day 0 possible nahi hota bloom ke liye)

        int r = *max_element(begin(bloomDay), end(bloomDay));  
        // sabse zyada wait karna padega itna, isse aage koi naya flower khilega hi nahi

        // impossible check: agar total zaroori flowers (m*k) available flowers (n) se zyada hain
        // to koi din kaam nahi karega -> seedha -1
        if((long long) m*k > bloomDay.size())
        return -1;

        // Binary search on answer: hum "minimum day jispe possible() true ho" dhoond rahe hain
        while(l < r)
        {
            int mid = l + (r-l)/2;   // overflow-safe mid calculation

            int waiting_days = mid;

            if(possible(waiting_days, bloomDay, m, k))
            {
                // agar mid din kaafi hai, to shayad isse kam din mein bhi ho jaaye
                // isliye mid ko range mein rakhte hue right ko chhota karo
                r = mid;
            }

            else
            {
                // mid din kaafi nahi hai, to answer isse zyada hoga
                l = mid + 1;
            }
        }

        // jab l == r, wahi smallest valid day hai
        return l;
    }
};