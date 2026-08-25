class Solution {
public:

    int minTime(string s, vector<int>& order, int k) {
        
        int n = order.size();
        set<int> star_idx_set;

        star_idx_set.insert(-1);
        star_idx_set.insert(n);

        long long count = 0;

        int t=0;

        while(t<n)
        {
            int x = order[t];

            star_idx_set.insert(x);

            auto it = star_idx_set.find(x);
            // int star_idx = *it;

            auto prev_it = prev(it);  
            auto next_it = next(it);

            int before = *prev_it;
            int after = *next_it;

            count += 1LL*(x - before) * (after - x);

            if(count >= k)
            return t;

            else
            t++;

        }

        return -1;
    }
};