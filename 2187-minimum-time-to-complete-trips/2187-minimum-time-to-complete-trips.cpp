
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

    bool possibleHai(long long given_time, vector<int> time, int totalTrips )
    {
        long long actual_trips = 0;

        for(int &t : time)
        {
            actual_trips += given_time/t;
        }

        return actual_trips >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long l = 1;

        long long r = (long long) *min_element( begin(time) , end(time)) * totalTrips;

        while(l<r)
        {
            long long mid_time = l + (r-l)/2;

            if( possibleHai(mid_time,time, totalTrips ) )
            r = mid_time;

            else
            l = mid_time + 1;
        }

        return l;
    }
};