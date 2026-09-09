
//BRUTE FORCE

// class MedianFinder {
// public:
    
//     vector<int> nums;

//     MedianFinder() {
        
//     }
    
//     void addNum(int num) {
        
//         int i=0;

//         while(i<nums.size() && nums[i] < num)
//         i++;

//         nums.insert( nums.begin()+ i, num);
//     }
    
//     double findMedian() {
        
//         int  n = nums.size();

//         if( n %  2 == 0)
//         {
        
//         return ((double) nums[n/2] + (double)nums[n/2 - 1])/2;
//         }

        

//         return nums[n/2];
//     }
// };


class MedianFinder {
public:
    
    priority_queue<int> left_max_heap;
    priority_queue< int, vector<int> , greater<int>> right_min_heap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if( left_max_heap.empty() || left_max_heap.top() > num)
        left_max_heap.push( num );

        else
        right_min_heap.push( num );

        if( left_max_heap.size() > right_min_heap.size() + 1)//transfer from left to right
        {
            right_min_heap.push( left_max_heap.top());
            left_max_heap.pop();
        }

        else if( left_max_heap.size() < right_min_heap.size()) // transfer right to left
        {
            left_max_heap.push( right_min_heap.top());
            right_min_heap.pop();
        }
        
    }
    
    double findMedian() {

        double median;
        if( left_max_heap.size() == right_min_heap.size())
        {
            median = ( (double)left_max_heap.top()  + (double)right_min_heap.top() )/2;
        }

        else
        {
            median = (double)left_max_heap.top() ;
        }
        
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */