// class Solution {
// public:

//     typedef pair<int, int> P;

//     // struct lambda{
//     //     bool operator()( P &p1, P &p2)
//     //     {
//     //         return p1.second > p2.second; //maintaining a min heap
//     //     }
//     // };
//     vector<int> topKFrequent(vector<int>& nums, int k) {
        
//         // priority_queue< P, vector<P> , lambda> pq; //min heap --- here i have implemented the comparator myself for min heap

//         priority_queue< P, vector<P> , greater<P>> pq; //min heap  ---- greater<P> is inbuilt comparoator for min heap
 

//         unordered_map<int, int> mp;

//         for( auto &it: nums)
//         {
//             mp[it]++;
//         }


//         //nlogk ---- pushing all in the heap
//         for( auto &it : mp)  
//         {
//             int value = it.first;
//             int freq =  it.second;

//             pq.push( {freq, value}); //log k

//              if( pq.size() > k) //min heap ka size atmost k rahega ..jese hi k se bada pop teh minimu from top
//             {
//                 pq.pop();
//             }
//         }

//         vector<int> result;
//         while(!pq.empty() && k>0)
//         {
//             P temp = pq.top();
//             pq.pop();

//             result.push_back( temp.second); //temp.second has value
//             k--;
//         }

//         return result;
//     }
// };

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Store the frequency of every distinct number.
        //
        // Example:
        // nums = [1,1,1,2,2,3]
        //
        // mp = {
        //     1 : 3,
        //     2 : 2,
        //     3 : 1
        // }
        unordered_map<int, int> mp;

        for (auto &it: nums)
        {
            mp[it]++;
        }

        int n = nums.size();

        // Create n + 1 buckets.
        //
        // The bucket index represents the frequency.
        //
        // bucket[1] contains numbers occurring once.
        // bucket[2] contains numbers occurring twice.
        // bucket[3] contains numbers occurring three times.
        //
        // Frequency can range from 1 to n.
        vector<vector<int>> bucket(n+1);

        // Place each number into its corresponding
        // frequency bucket.
        //
        // it.second = frequency
        // it.first  = number
        //
        // Example:
        // If number = 1 and frequency = 3:
        // bucket[3].push_back(1);
        for (auto &it: mp)
        {
            bucket[it.second].push_back(it.first);
        }

        // Start from the last bucket because it represents
        // the highest possible frequency.
        //
        // bucket.size() = n + 1
        // Last valid index = n
        int i = bucket.size()-1;

        vector<int> result;

        // Traverse the buckets from highest frequency
        // to lowest frequency.
        while (i >= 0)
        {
            // If the current bucket is empty,
            // move to the next lower frequency.
            if (bucket[i].size() == 0)
            {
                i--;
                continue;
            }

            else
            {
                // Process all numbers in the current bucket.
                //
                // back() accesses the last element in O(1).
                // pop_back() removes the last element in O(1).
                //
                // We stop when the bucket becomes empty
                // or when we have collected k elements.
                while (bucket[i].size() > 0 && k > 0)
                {
                    // Take a number from the current frequency bucket.
                    result.push_back(bucket[i].back());

                    // Remove the selected number from the bucket.
                    // Removing from the back takes O(1) time.
                    bucket[i].pop_back();

                    // One required element has been collected.
                    k--;
                }
            }

            // Move to the next lower frequency bucket.
            i--;
        }

        return result;
    }
};