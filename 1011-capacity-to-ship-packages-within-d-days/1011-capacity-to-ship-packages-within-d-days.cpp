class Solution {
public:

    // Checks whether it is possible to ship all packages
    // within 'days' days using the given ship capacity.
    bool canShip(vector<int>& weights, int capacity, int days)
    {
        // We will use at least one day because there is
        // at least one package.
        int days_required = 1;

        int n = weights.size();

        // Stores the total weight loaded on the current day.
        int weight_for_the_day = 0;

        int i = 0;

        while(i < n)
        {
            // Try to put the current package on the
            // current day.
            weight_for_the_day += weights[i];

            // If adding this package exceeds the ship's capacity,
            // we cannot keep it on the current day.
            if(weight_for_the_day > capacity)
            {
                // Start a new day.
                // The current package becomes the first
                // package of the new day.
                weight_for_the_day = weights[i];

                // We have used one more day.
                days_required++;
            }

            i++;
        }

        // If the required number of days is within
        // the allowed number of days, this capacity works.
        return days_required <= days;
    }


    int shipWithinDays(vector<int>& weights, int days) {

        int n = weights.size();

        // Minimum possible capacity:
        // The ship must be able to carry the heaviest package.
        int low = *max_element(begin(weights), end(weights));

        // Calculate the total weight of all packages.
        int total_weight = 0;

        for(int i = 0; i < n; i++)
        {
            total_weight += weights[i];
        }

        // Maximum possible capacity:
        // If the ship can carry everything in one day,
        // its capacity needs to equal the total weight.
        int high = total_weight;

        // Binary search for the first capacity
        // that can ship everything within 'days' days.
        while(low <= high)
        {
            // Avoids possible overflow compared to (low + high) / 2.
            int mid = low + (high - low) / 2;

            int current_capacity = mid;

            // Check whether this capacity is sufficient.
            if(canShip(weights, current_capacity, days))
            {
                // This capacity works.
                // But we want the smallest working capacity,
                // so search towards the left.
                high = mid - 1;
            }
            else
            {
                // This capacity does not work.
                // We need a larger capacity.
                low = mid + 1;
            }
        }

        // At the end:
        //
        // high = last invalid capacity
        // low  = first valid capacity
        //
        // Therefore, low is the answer.
        return low;
    }
};