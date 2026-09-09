class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int n = points.size();

        priority_queue< pair< int, vector<int> > > squared_distance;

      

        for(int i=0; i< points.size(); i++)
        {
            long long x_squared = 1LL* points[i][0] * points[i][0];
            long long y_squared = 1LL* points[i][1] * points[i][1];

            long long squared_ditance_of_current_point = x_squared + y_squared;

            squared_distance.push( {squared_ditance_of_current_point, {points[i][0], points[i][1]}} );

            if( squared_distance.size() > k)
            {
                squared_distance.pop();
            }

        }

        vector< vector<int>> ans;

        while( !squared_distance.empty())
        {
            ans.push_back( squared_distance.top().second);
            squared_distance.pop();
        }


        return ans;
    }
};