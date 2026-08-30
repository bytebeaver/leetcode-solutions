class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();

        int left_sum = 0;
        int right_sum = 0;

        for(int i=0; i<=k-1; i++)
        left_sum += cardPoints[i];

        int max_points = left_sum;

        int right_index=n-1;

        for(int left_index = k-1; left_index>=0; left_index--)
        {
            left_sum -= cardPoints[left_index];
            right_sum += cardPoints[right_index];

            max_points = max(max_points, left_sum + right_sum);

            right_index -= 1;
        }

        return max_points;
    }
};