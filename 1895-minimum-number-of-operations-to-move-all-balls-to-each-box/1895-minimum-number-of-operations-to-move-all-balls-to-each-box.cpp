class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(); // Length of the input string `boxes`
        vector<int> answer(n, 0); // Initialize the answer vector with zeros, size equal to `n`

        int cummulative_value = 0;       // Tracks the total count of balls encountered so far
        int cummulative_value_sum = 0;  // Tracks the cumulative distance of balls to the current index

        // Step 1: Calculate the number of operations to move all balls
        // to each box `i` from the boxes that lie on the left of `i`.
        for (int i = 0; i < n; i++) {
            // Store the current cumulative distance in the answer for index `i`
            answer[i] = cummulative_value_sum;

            // If the current box has a ball (boxes[i] == '1'), increment the cumulative count of balls
            if (boxes[i] == '1') {
                cummulative_value += 1; // Add one ball to the count
            }

            // Add the current cumulative count of balls to the cumulative distance
            cummulative_value_sum += cummulative_value;

            // Example for index 0 to n-1 (for boxes = "110"):
            // i = 0 -> answer[0] = 0, cummulative_value = 1, cummulative_value_sum = 1
            // i = 1 -> answer[1] = 1, cummulative_value = 2, cummulative_value_sum = 3
            // i = 2 -> answer[2] = 3, cummulative_value = 2, cummulative_value_sum = 5
        }

        // Reset cumulative variables to calculate the right-side contribution
        cummulative_value = 0;
        cummulative_value_sum = 0;

        // Step 2: Calculate the number of operations to move all balls
        // to each box `i` from the boxes that lie on the right of `i`.
        for (int i = n - 1; i >= 0; i--) {
            // Add the current cumulative distance (right side contribution) to the answer
            answer[i] += cummulative_value_sum;

            // If the current box has a ball (boxes[i] == '1'), increment the cumulative count of balls
            if (boxes[i] == '1') {
                cummulative_value += 1; // Add one ball to the count
            }

            // Add the current cumulative count of balls to the cumulative distance
            cummulative_value_sum += cummulative_value;

            // Example for index n-1 to 0 (for boxes = "110"):
            // i = 2 -> answer[2] = 3 + 0 = 3, cummulative_value = 1, cummulative_value_sum = 1
            // i = 1 -> answer[1] = 1 + 1 = 2, cummulative_value = 2, cummulative_value_sum = 3
            // i = 0 -> answer[0] = 0 + 3 = 3, cummulative_value = 2, cummulative_value_sum = 5
        }

        return answer; // Return the final answer array
    }
};

// class Solution {
// public:

//     //brute force approach 1
//     vector<int> minOperations(string boxes) {
//         int n = boxes.length();
//         vector<int>answer(n,0);

//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<n ;j++)
//             {
//                 if(boxes[j]=='1')
//                 answer[i]+=abs(j-i);
//             }
//         }

//         return answer;
//     }
// };