class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n = profits.size();
        
        vector<pair<int, int>> vec(n);

        for( int i=0; i<n ; i++)
        {
            vec[i] =  {capital[i], profits[i]} ;
        }

        sort(vec.begin(), vec.end());

        int i=0; 

        priority_queue< int> maxProfit;
        while( i<n && k>0 )
        {
            while( i<n && vec[i].first <= w)
            {
                maxProfit.push(vec[i].second);
                i++;
            }

            if( maxProfit.empty()) break;

            if( !maxProfit.empty())
            {
                w += maxProfit.top();
                maxProfit.pop();
                k--;
            }

            
            if( k == 0)
            break;
        }


        while( !maxProfit.empty() && k > 0)
        {
            w += maxProfit.top();
            maxProfit.pop();
            k--;

            if( k == 0)
            break;
        }

        return w;
    }
};