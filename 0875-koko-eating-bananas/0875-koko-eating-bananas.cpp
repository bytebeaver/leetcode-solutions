class Solution {
public:

    // Checks: if Koko eats at 'rate_of_eating' bananas/hour,
    // can she finish all piles within 'h' hours?
    bool canEat(int rate_of_eating, vector<int> piles, int h)
    {
        int actual_hours = 0;

        for(auto &it : piles)
        {
            // integer division gives full hours needed for this pile
            actual_hours += it / rate_of_eating;

            // leftover bananas (less than rate_of_eating) still need
            // one more hour, since Koko can't eat from another pile
            // in that same hour once she starts a pile
            if(it % rate_of_eating != 0)
                actual_hours++;
        }

        // if total hours needed fits within h, this speed works
        return actual_hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        // minimum possible speed: 1 banana/hour
        int l = 1;

        // maximum useful speed: no point going faster than the
        // biggest pile, since 1 pile takes max 1 hour at that speed
        int r = *max_element(begin(piles), end(piles));

        // classic binary search on answer:
        // find smallest k such that canEat(k) is true
        while(l < r)
        {
            int mid_rate = l + (r - l) / 2; // avoids overflow vs (l+r)/2

            if(canEat(mid_rate, piles, h))
            {
                // mid_rate works -> maybe a smaller speed also works
                // so shrink search space from the right, but keep mid_rate
                // as a valid candidate (don't do mid_rate - 1)
                r = mid_rate;
            }
            else
            {
                // mid_rate too slow -> need faster speed
                // mid_rate itself is proven invalid, so exclude it
                l = mid_rate + 1;
            }
        }

        // l == r here: this is the minimum valid eating speed
        return l;
    }
};