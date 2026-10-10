
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        int n = stones.size();

        // Max-heap to get the heaviest stone at the top
        priority_queue<int> pq;

        // Insert all stones into the max-heap
        for (auto &it : stones) {
            pq.push(it);
        }

        // Keep smashing stones until at most one stone remains
        while (pq.size() > 1) {

            // Extract the two heaviest stones
            int heavy1 = pq.top();
            pq.pop();

            int heavy2 = pq.top();
            pq.pop();

            // If both stones have equal weight, both are destroyed
            if (heavy1 == heavy2) {

                // If no stones remain, the answer is 0
                // Example: [2, 2] -> both stones are destroyed
                if (pq.empty()) return 0;

                // Otherwise, continue with the remaining stones
                continue;
            }

            // If weights differ, the heavier stone remains
            // with weight heavy1 - heavy2 and is inserted back
            else {
                pq.push(heavy1 - heavy2);
            }
        }

        // If one stone remains, return its weight
        return pq.top();
    }
};
