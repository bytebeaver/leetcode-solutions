class KthLargest {
public:

    int k;
    priority_queue<int>left_max_heap;
    priority_queue<int, vector<int>, greater<int>>right_min_heap;

    KthLargest(int k, vector<int>& nums) {
         this->k = k; 
        for(int i=0; i<nums.size(); i++)
        {
        
        right_min_heap.push(nums[i]);

        if(right_min_heap.size() >= k)
        {
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }

        }

       
    }
    
    int add(int val) {

    
      right_min_heap.push(val);

    if (right_min_heap.size() >= this->k)
    {
        left_max_heap.push(right_min_heap.top());
        right_min_heap.pop();
    }

    return left_max_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */