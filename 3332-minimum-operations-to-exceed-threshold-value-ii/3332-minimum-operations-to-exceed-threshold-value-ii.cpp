class Solution {
 public:
  int minOperations(vector<int>& nums, int k)
 {

    priority_queue<long, vector<long>, greater<long> > minHeap;
    
    //add all the number of nums in priority queue
    for( int &num : nums)
    minHeap.push(num);

    int count =0;

    while(minHeap.size() >1 && minHeap.top() < k)
    {
        long smallest = minHeap.top();
        minHeap.pop();

        long second_smallest = minHeap.top();
        minHeap.pop();

        minHeap.push(smallest*2 + second_smallest);

        count++;
    }
    return count;
  }
};