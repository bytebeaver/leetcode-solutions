class Solution {
public:

    bool canEat(int rate_of_eating , vector<int> piles, int h)
    {
        int actual_hours=0;

        for(auto &it : piles)
        {
            actual_hours += it/rate_of_eating;

            if(it % rate_of_eating !=0)
            actual_hours++;
        }

        return actual_hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
    int l = 1;

    int r = *max_element(begin(piles), end(piles));

    while(l<r)
    {
        int mid_rate = l + (r-l)/2;

        if(canEat(mid_rate, piles,h))
        {
            r=mid_rate;
        }
        
        else
        l = mid_rate + 1;

    }

    return l;
}
};