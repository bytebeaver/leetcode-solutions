class MedianFinder {
public:
    
    vector<int> nums;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        int i=0;

        while(i<nums.size() && nums[i] < num)
        i++;

        nums.insert( nums.begin()+ i, num);
    }
    
    double findMedian() {
        
        int  n = nums.size();

        if( n %  2 == 0)
        {
        
        return ((double) nums[n/2] + (double)nums[n/2 - 1])/2;
        }

        

        return nums[n/2];
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */