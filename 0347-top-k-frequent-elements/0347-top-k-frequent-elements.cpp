class Solution {
public:

    typedef pair<int, int> P;

    // struct lambda{
    //     bool operator()( P &p1, P &p2)
    //     {
    //         return p1.second > p2.second; //maintaining a min heap
    //     }
    // };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // priority_queue< P, vector<P> , lambda> pq; //min heap --- here i have implemented the comparator myself for min heap

        priority_queue< P, vector<P> , greater<P>> pq; //min heap  ---- greater<P> is inbuilt comparoator for min heap
 

        unordered_map<int, int> mp;

        for( auto &it: nums)
        {
            mp[it]++;
        }


        //nlogk ---- pushing all in the heap
        for( auto &it : mp)  
        {
            int value = it.first;
            int freq =  it.second;

            pq.push( {freq, value}); //log k

             if( pq.size() > k) //min heap ka size atmost k rahega ..jese hi k se bada pop teh minimu from top
            {
                pq.pop();
            }
        }

        vector<int> result;
        while(!pq.empty() && k>0)
        {
            P temp = pq.top();
            pq.pop();

            result.push_back( temp.second);
            k--;
        }

        return result;
    }
};