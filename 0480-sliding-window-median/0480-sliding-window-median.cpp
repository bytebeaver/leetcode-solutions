class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        

        priority_queue< pair<int, int>> left_max_heap;
        
        priority_queue< pair<int, int>, vector<pair<int,int> >, greater< pair<int,int> >  > right_min_heap;

        int n = nums.size();
        vector<bool> flag(n,false);

        vector<double> result;

        int stale_nodes_in_left_max_heap = 0;
        int stale_nodes_in_right_min_heap = 0;

        for( int i=0; i<n ; i++)
        {
            if( left_max_heap.empty() || left_max_heap.top().first >= nums[i] )
            {
            left_max_heap.push({nums[i], i});
            flag[i] = true;
            }

            else
            {
            right_min_heap.push( {nums[i], i});
            flag[i] = false;
            }

            if( i>= k)   
            {
                // index_going_out of the window is = i-k;

                if( flag[ i-k] == true)
                stale_nodes_in_left_max_heap++;

                else if( flag[ i-k] == false)
                stale_nodes_in_right_min_heap++;

                while( !left_max_heap.empty() && left_max_heap.top().second <= i-k) //i-k is the index just before the window start
                {
                left_max_heap.pop();
                stale_nodes_in_left_max_heap--;
                }

                while(!right_min_heap.empty() && right_min_heap.top().second <= i-k)
                {
                right_min_heap.pop();
                stale_nodes_in_right_min_heap--;
                }

            }

            //rebalance ...to har element ke add hone pr krana hoga

            while( left_max_heap.size() - stale_nodes_in_left_max_heap > right_min_heap.size() + 1 - stale_nodes_in_right_min_heap) //left se right me transfer krna hoga..but usse pehle get rid of any stale nodes on top of left
            {
                if( !left_max_heap.empty() && left_max_heap.top().second <= i - k)
                {
                left_max_heap.pop();
                stale_nodes_in_left_max_heap--;
                }

                else
                {
                right_min_heap.push( left_max_heap.top());

                flag[ left_max_heap.top().second] = false;

                left_max_heap.pop();

                }

            }


             while( left_max_heap.size() - stale_nodes_in_left_max_heap < right_min_heap.size() - stale_nodes_in_right_min_heap) 
            {
                if( !right_min_heap.empty() && right_min_heap.top().second <= i-k)
                {
                right_min_heap.pop();
                stale_nodes_in_right_min_heap--;
                }

                else
                {
                left_max_heap.push( right_min_heap.top());

                flag[right_min_heap.top().second ] = true;

                right_min_heap.pop();
                }

            }

            //after rebalancing there still can be stale nodes present on heaps lets get rid of them:
              while( !left_max_heap.empty() && left_max_heap.top().second <= i-k)
                {
                left_max_heap.pop();
                stale_nodes_in_left_max_heap--;
                }

                while(!right_min_heap.empty() && right_min_heap.top().second <= i-k)
                {
                right_min_heap.pop();
                stale_nodes_in_right_min_heap--;
                }

                //now time to get the median of the window
                if( i>= k-1) //we have hit the window ...pehli baar k-1 pr hit hogi ..ex k=3 0 1 2 ..uske baad to hoti hi rahegi....ek ayega ek jayega 
                {
                    if( k%2 == 1)
                    {
                        double median = left_max_heap.top().first;
                        result.push_back( median);
                    }

                    else
                    {
                     double median = ((double)left_max_heap.top().first +(double) right_min_heap.top().first)/2.0;
                        result.push_back( median);
                    }
                }

        }

        return result;
    }
};