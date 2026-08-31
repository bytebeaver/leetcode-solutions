class Solution {
public:


     bool canShip( vector<int> &weights, int capacity, int days)
     {
        //sum of all elements of the weights array divided by current capacity should be less than days 
        // return total_weight/capacity <= days;

        int days_required = 1;
        int n = weights.size();

        int weight_for_the_day = 0;

        int i=0;
        while(i<n)
        {
            weight_for_the_day += weights[i];
            
            if(weight_for_the_day > capacity )
            {
                weight_for_the_day= weights[i];
                days_required +=1;
                
            }

            i++;
        }
        return days_required <= days;
     }


    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        int low = *max_element(begin(weights), end(weights));
        
        int total_weight = 0;

        for(int i=0; i<n; i++)
        {
            total_weight += weights[i];
        }

        int high = total_weight;

        while( low <= high)
        {
            int mid = low + (high-low)/2;

            int current_capacity = mid;

            if( canShip(weights, current_capacity, days))
            {
                high = mid-1;
            }

            else
            {
                low = mid+1;
            }
        }

        return low;
    }
};