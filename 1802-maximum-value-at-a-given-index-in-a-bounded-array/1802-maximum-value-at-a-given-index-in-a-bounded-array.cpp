class Solution {
public:
    
    typedef long long ll;

    ll get_sum_by_formula(ll count , ll x, ll extra_ones )
    {
        return ( x*count ) - (count)*(count+1)/2 + extra_ones;
    }

    ll is_this_x_valid(int n, int index, ll x)
    {
        ll left_count = (ll)index;

        ll right_count = (ll) (n-index-1);

        ll left_sum = get_sum_by_formula( min( x-1, left_count) , x , max( (ll)0, left_count-(x-1) ) );

         ll right_sum = get_sum_by_formula( min( x-1, right_count) , x , max((ll) 0, right_count-(x-1) ) );

         return left_sum + x + right_sum;
    }


    int maxValue(int n, int index, int maxSum) {
        
        //search space for x where x is the result to be output

        ll  low = 1;
        ll high = maxSum;

        int max_value=1;

        while(low<= high)
        {
            ll mid = low + (high-low)/2;

            ll x=mid;

            ll sum =  is_this_x_valid(n , index, x);

            if(sum <= maxSum)
            {
                //this is a possible answer
                max_value = max( (ll)max_value , x);
                low = mid+1;
            }

            else if( sum > maxSum)
            {
                high = mid-1;
            }
        }
    return max_value;
    }
};