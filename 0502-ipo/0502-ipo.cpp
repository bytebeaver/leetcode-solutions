class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n = profits.size();
        
        // Store each project as {required capital, profit}.
        // This allows us to sort projects based on the capital required.
        vector<pair<int, int>> vec(n);

        for(int i = 0; i < n; i++)
        {
            vec[i] = {capital[i], profits[i]};
        }

        // Sort projects in increasing order of required capital.
        // This helps us efficiently find all projects that become affordable
        // as our available capital 'w' increases.
        sort(vec.begin(), vec.end());

        int i = 0;

        // Max-heap containing profits of all currently affordable projects.
        // The project with the highest profit will always be at the top.
        priority_queue<int> maxProfit;

        while(k > 0)
        {
            // Add every project whose required capital is <= current capital.
            // Since vec is sorted by capital, we only move 'i' forward.
            while(i < n && vec[i].first <= w)
            {
                maxProfit.push(vec[i].second);
                i++;
            }

            // If no project is affordable, we cannot proceed further.
            if(maxProfit.empty())
                break;

            // Choose the currently affordable project with maximum profit.
            // Completing it increases our available capital.
            w += maxProfit.top();
            maxProfit.pop();

            k--;
        }

       

        return w;
    }
};