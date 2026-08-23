class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector< vector<int>> result;
        sort(intervals.begin(), intervals.end());

        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        int n = intervals.size();

        for(int i=1; i<n; i++)
        {
            int start2 = intervals[i][0];
            int end2   = intervals[i][1];

            //merge karna hai ya nahi:
            if( end1 >= start2)
            {
                //merge krenge
                start1 = start1;
                end1   = max(end1, end2);

            }

            else
            {
                result.push_back({start1, end1});
                start1 = start2;
                end1   = end2;
            }
            
        }

        result.push_back({start1, end1});//last me ek interval bach jayega for loop mein

        return result;

    }
};