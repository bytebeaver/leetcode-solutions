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

     bool possible(int waiting_days, vector<int>bloomDay, int m , int k)
     {
            //we will check if it possible to make m bouqets if we wait the given number of waiting days
            int counter = 0;

            for(auto & it : bloomDay)
            {
                if(it <= waiting_days)
                {
                    counter++;
                    if(counter == k)
                    {   
                        counter=0;
                        m--;
                        
                        if(m==0)
                        return true;
                    }
                }

                else if(it > waiting_days)
                {
                    counter =0;
                }
            }

        return false;
     }


    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int l = 1;//minimum ek din to wait krenge

        int r = *max_element(begin(bloomDay), end(bloomDay));

        if((long long) m*k > bloomDay.size())
        return -1;

        while(l<r)
        {
            int mid = l+ (r-l)/2;

            int waiting_days = mid;

            if(possible(waiting_days, bloomDay, m, k))
            {
                r=mid;
            }

            else
            {
                l = mid+1;
            }
        }

    return l;
    }
};