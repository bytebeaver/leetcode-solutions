class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();

        /*
            vec[i] stores 3 pieces of information:

            vec[i][0] = nums1 value
            vec[i][1] = original index of that element
            vec[i][2] = corresponding nums2 value

            Example:
            nums1 = [3, 1, 2]
            nums2 = [5, 4, 6]

            vec before sorting:
            [3, 0, 5]
            [1, 1, 4]
            [2, 2, 6]

            We keep the original index because after sorting by nums1,
            we still need to put the answer back at the correct position.
        */
        vector<vector<int>> vec(n);

        for (int i = 0; i < n; i++) {
            vec[i] = {nums1[i], i, nums2[i]};
        }

        /*
            Sort by nums1 value.

            Since vec[i][0] is nums1 value, sorting vec automatically
            sorts the elements according to nums1.

            After sorting:
            vec[i][0] -> current nums1 value
            vec[i][1] -> original index in the input arrays
            vec[i][2] -> corresponding nums2 value
        */
        sort(vec.begin(), vec.end());

        // result[original_index] will store the answer for that index.
        vector<long long> result(n);

        /*
            Min-heap containing the nums2 values currently selected.

            We use a min-heap because whenever we have more than k
            elements, we want to remove the smallest nums2 value.

            pq.top() = smallest nums2 value currently in the heap.
        */
        priority_queue<int, vector<int>, greater<int>> pq;

        // Sum of all nums2 values currently present in the heap.
        long long sum = 0;

        for (int i = 0; i < n; i++) {

            /*
                IMPORTANT:

                vec[i][0] = current nums1 value
                vec[i][1] = original index of current element
                vec[i][2] = nums2 value corresponding to current element

                If the current nums1 value is equal to the previous
                nums1 value, we must use the same sum that existed
                BEFORE adding the current group of equal nums1 values.

                result[vec[i-1][1]]:
                    answer stored for the previous element's original index.

                vec[i-1][1] gives us that previous element's ORIGINAL
                INDEX in nums1/nums2/result.
            */
            if (i > 0 && vec[i - 1][0] == vec[i][0]) {

                /*
                    vec[i][1] = original index of the current element.

                    We copy the previously calculated result to this
                    original index because both elements have the same
                    nums1 value.
                */
                long long temp = result[vec[i - 1][1]];

                result[vec[i][1]] = temp;
            }
            else {

                /*
                    vec[i][1] = original index of the current element.

                    sum represents the sum of the best k nums2 values
                    from elements having a STRICTLY SMALLER nums1 value.

                    Store that sum as the answer for the current
                    element's original position.
                */
                result[vec[i][1]] = sum;
            }

            /*
                Add the current element's nums2 value to the heap.

                vec[i][2] means:
                    nums2 value corresponding to the current element.
            */
            pq.push(vec[i][2]);

            // Keep track of the sum of nums2 values in the heap.
            sum += vec[i][2];

            /*
                We are allowed to keep at most k nums2 values.

                If the heap now contains more than k elements,
                remove the smallest nums2 value.

                pq.top() gives the smallest nums2 value because
                pq is a MIN-HEAP.
            */
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
        }

        return result;
    }
};