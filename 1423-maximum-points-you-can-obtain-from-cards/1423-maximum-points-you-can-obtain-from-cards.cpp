class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        // Sum of cards currently taken from the left side
        int left_sum = 0;

        // Sum of cards currently taken from the right side
        int right_sum = 0;

        // Initially, take all k cards from the left
        for (int i = 0; i <= k - 1; i++)
            left_sum += cardPoints[i];

        // Initially, our score is the sum of first k cards
        int max_points = left_sum;

        // Start taking cards from the rightmost position
        int right_index = n - 1;

        // Gradually replace left cards with right cards
        for (int left_index = k - 1;
             left_index >= 0;
             left_index--)
        {
            // Remove one card from the left selection
            left_sum -= cardPoints[left_index];

            // Add one card from the right selection
            right_sum += cardPoints[right_index];

            // Calculate the score for this combination
            int current_score = left_sum + right_sum;

            // Update maximum score
            max_points = max(max_points, current_score);

            // Move to the next card from the right
            right_index--;
        }

        return max_points;
    }
};