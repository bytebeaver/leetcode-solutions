
//BRUTE FORCE

// class Solution {
// public:
//     long long minimumTime(vector<int>& time, int totalTrips) {
        
//         long long T = 1;

        
//         while( true)
//         {
//             long long target = 0;
//             for(int i=0; i<time.size(); i++)
//             {
//                 target += (T/(long long)time[i]);
//             }

//             if(target >= totalTrips)
//             return T;

//             else 
//             T++;


//         }

//     return 0;
//     }
// };

class Solution {
public:

    // Checks: agar 'given_time' tak har bus apna kaam kare,
    // to kya total trips >= totalTrips ho jaayenge?
    bool possibleHai(long long given_time, vector<int> time, int totalTrips)
    {
        long long actual_trips = 0;

        // Har bus ke trips ko sum karo: given_time / time[i]
        // (integer division => poore trips hi count honge, adhoore nahi)
        for(int &t : time)
        {
            actual_trips += given_time / t;
        }

        // int totalTrips implicitly long long mein promote ho jaayega
        // is comparison ke liye — safe, koi data loss nahi
        return actual_trips >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        
        // Left bound: sabse chhota possible time
        long long l = 1;

        // Right bound: agar sirf fastest bus akela kaam kare,
        // to itne time mein totalTrips guaranteed complete ho jaayenge
        long long r = (long long) *min_element(begin(time), end(time)) * totalTrips;

        while(l < r)
        {
            // Overflow-safe midpoint calculation
            long long mid_time = l + (r - l) / 2;

            if(possibleHai(mid_time, time, totalTrips))
                // mid khud valid answer ho sakta hai -> retain karo,
                // ab chhote answers dhoondo
                r = mid_time;

            else
                // mid kabhi answer nahi ban sakta -> completely discard karo
                l = mid_time + 1;
        }

        // l == r yahan -> yehi minimum valid time hai
        return l;
    }
};