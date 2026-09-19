class Solution {
public:

    long long totalCost(vector<int>& costs, int k, int candidates) {

        int n = costs.size();

        // Two min heaps:
        // pq1 stores available workers from the left side.
        // pq2 stores available workers from the right side.
        //
        // The minimum cost is always available at the top
        // of each priority queue.
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;

        int hired = 0;

        // Use long long because the total hiring cost
        // can exceed the range of a normal int.
        long long ans = 0;

        // i points to the next worker from the left.
        // j points to the next worker from the right.
        int i = 0;
        int j = n - 1;

        // Continue until exactly k workers are hired.
        while (hired < k)
        {
            // Fill the left min heap with up to candidates workers.
            //
            // Each worker is pushed at most once overall.
            // Each push takes O(log candidates).
            while (pq1.size() < candidates && i <= j)
            {
                pq1.push(costs[i]);
                i++;
            }

            // Fill the right min heap with up to candidates workers.
            //
            // The condition j >= i prevents the same worker
            // from being inserted into both heaps.
            //
            // Each push takes O(log candidates).
            while (pq2.size() < candidates && j >= i)
            {
                pq2.push(costs[j]);
                j--;
            }

            // Get the minimum cost from the left heap.
            //
            // If the heap is empty, use INT_MAX so that
            // the right heap will be selected.
            int min_from_pq1 =
                (pq1.size() > 0) ? pq1.top() : INT_MAX;

            // Get the minimum cost from the right heap.
            //
            // If the heap is empty, use INT_MAX so that
            // the left heap will be selected.
            int min_from_pq2 =
                (pq2.size() > 0) ? pq2.top() : INT_MAX;

            // If both minimum costs are equal,
            // choose the left heap as required.
            //
            // Accessing top() takes O(1) time.
            if (min_from_pq1 <= min_from_pq2)
            {
                // Add the selected worker's cost
                // to the total hiring cost.
                ans += min_from_pq1;

                // Remove the selected worker.
                // pop() takes O(log candidates) time.
                pq1.pop();
            }
            else
            {
                // The right heap has the smaller cost.
                ans += min_from_pq2;

                // Remove the selected worker from
                // the right min heap.
                // pop() takes O(log candidates) time.
                pq2.pop();
            }

            // One worker has now been hired.
            hired++;
        }

        return ans;
    }
};