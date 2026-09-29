class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int x : nums) {
            minHeap.push(x);

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    int add(int val) {
        minHeap.push(val);

        if (minHeap.size() > k) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};























// class KthLargest {
// public:

//     int k;  // Stores the value of k so that all class methods can access it

//     // Max-heap: stores the elements outside the k-1 largest elements.
//     // Its top is the largest among these remaining elements,
//     // which is the kth largest element overall.
//     priority_queue<int> left_max_heap;

//     // Min-heap: stores the k-1 largest elements.
//     // Its top is the smallest among these k-1 elements.
//     priority_queue<int, vector<int>, greater<int>> right_min_heap;

//     KthLargest(int k, vector<int>& nums) {

//         this->k = k;  // Save the constructor parameter in the class member

//         // Process all the initial elements one by one
//         for (int i = 0; i < nums.size(); i++)
//         {
//             // Insert the current element into the right min-heap
//             right_min_heap.push(nums[i]);

//             // If the right heap reaches size k, it has one
//             // extra element because we want to retain only k-1
//             // elements in this heap.
//             if (right_min_heap.size() >= k)
//             {
//                 // Move the smallest element of the right heap
//                 // into the left max-heap.
//                 // This element is no longer among the k-1
//                 // largest elements.
//                 left_max_heap.push(right_min_heap.top());

//                 // Remove that smallest element from the right heap
//                 right_min_heap.pop();
//             }
//         }
//     }

//     int add(int val) {

//         // Insert the newly arriving element into the right min-heap
//         right_min_heap.push(val);

//         // If the right heap reaches size k, move its smallest
//         // element to the left heap to restore the size k-1.
//         if (right_min_heap.size() >= this->k)
//         {
//             // Transfer the smallest element from the right heap
//             // to the left max-heap.
//             left_max_heap.push(right_min_heap.top());

//             // Remove the transferred element from the right heap
//             right_min_heap.pop();
//         }

//         // The largest element in the left heap is the kth largest
//         // element overall, assuming at least k elements exist.
//         return left_max_heap.top();
//     }
// };
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */