
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


//OPTIMAL USING 2 HEAPS 
class MedianFinder {
public:

    // Max Heap
    // Stores the LEFT HALF of the numbers.
    //
    // top() gives the largest element
    // in the left half.
    priority_queue<int> left_max_heap;


    // Min Heap
    // Stores the RIGHT HALF of the numbers.
    //
    // top() gives the smallest element
    // in the right half.
    priority_queue<int, vector<int>, greater<int>> right_min_heap;


    MedianFinder() {

    }


    void addNum(int num) {

        /*
            STEP 1: Decide which half 'num' belongs to.

            left_max_heap.top() represents the largest
            element currently present in the left half.

            If num is smaller than this boundary,
            it belongs to the LEFT half.

            Otherwise it belongs to the RIGHT half.
        */

        if (left_max_heap.empty() ||
            left_max_heap.top() > num)
        {
            left_max_heap.push(num);
        }
        else
        {
            right_min_heap.push(num);
        }


        /*
            STEP 2: Maintain the size condition.

            We want:

                left.size() == right.size()

            OR

                left.size() == right.size() + 1

            LEFT is allowed to have at most
            one extra element.
        */


        // CASE 1:
        // LEFT has at least 2 more elements than RIGHT.

        if (left_max_heap.size() >
            right_min_heap.size() + 1)
        {
            /*
                Move the largest element of LEFT
                to RIGHT.

                Since LEFT is a max heap,
                left_max_heap.top() is the largest
                element of LEFT.
            */

            right_min_heap.push(left_max_heap.top());

            left_max_heap.pop();
        }


        // CASE 2:
        // RIGHT has more elements than LEFT.

        else if (left_max_heap.size() <
                 right_min_heap.size())
        {
            /*
                Move the smallest element of RIGHT
                to LEFT.

                Since RIGHT is a min heap,
                right_min_heap.top() is the smallest
                element of RIGHT.
            */

            left_max_heap.push(right_min_heap.top());

            right_min_heap.pop();
        }
    }


    double findMedian() {

        /*
            If both heaps have the same size,
            the total number of elements is EVEN.

            Therefore the median is the average
            of:

                largest element of LEFT
                smallest element of RIGHT
        */

        if (left_max_heap.size() ==
            right_min_heap.size())
        {
            return (
                (double)left_max_heap.top() +
                (double)right_min_heap.top()
            ) / 2;
        }


        /*
            Otherwise LEFT has exactly one extra element.

            Therefore total number of elements is ODD.

            The median is the largest element
            of LEFT.
        */

        return (double)left_max_heap.top();
    }
};