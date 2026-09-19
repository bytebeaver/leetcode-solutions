// class Solution {
// public:

//     typedef pair< int, pair<int, int>> P;
//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

//         priority_queue< P, vector<P>> pq; //max-heap

//         int n = nums1.size();
//         int m = nums2.size();

//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<m ; j++)
//             {
//                 int sum = nums1[i] + nums2[j];

//                 if( pq.size() <k)
//                 pq.push( { sum, {i,j} } );

//                 else if( pq.size() >= k)
//                 {
//                     if( sum < pq.top().first)
//                     {
//                         pq.pop();
//                         pq.push( { sum, {i,j} } );
//                     }

//                     else if(sum >= pq.top(). first)
//                     break; //agr nums1[i] + nums2[j] >= pq.top().first hain to nums 2 me aane wale age sare elements ke liye bhi ye true hoga ...isliye hm break kr jate hain and nums1 me i ko aage badhate hain      
//                 }
//             }
//         }

//         vector<vector<int>> result;

//         while( !pq.empty())
//         {
//             auto temp = pq.top(); //pq.top will be like { sum , {i,j}}
//             pq.pop();

//             int i = temp.second.first;
//             int j = temp.second.second;

//             result.push_back( {nums1[i], nums2[j]});

//         }        

//         return result;
//     }
// };



class Solution {
public:

    typedef pair< int, pair<int, int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

      priority_queue<P, vector<P>, greater<P>> pq; //taking min heap

      int m = nums1.size();
      int n = nums2.size();

      int sum = nums1[0] + nums2[0];

       set<pair<int, int>> visited; //cant take unordered_set ..cpp doesnt allow unordered set for pair

      pq.push( {sum , {0,0}});
        visited.insert( {0,0}); 
      vector< vector<int>> result;

      while( k>0 && !pq.empty())
      {
        auto temp = pq.top();
        pq.pop();

        int i = temp.second.first;
        int j = temp.second.second;

        result.push_back( {nums1[i], nums2[j]});

        if( i+1 < m  && visited.find( {i+1, j}) == visited.end())
        {
            pq.push( {nums1[i+1] + nums2[j], {i+1,j}});
            visited.insert( {i+1, j} );
        }

        if( j+1 < n  && visited.find( {i, j+1}) == visited.end())
        {
            pq.push({ nums1[i] + nums2[j+1], {i,j+1} });
            visited.insert( {i, j+1} );
        }

        k--;

        
      }

      return result;
    }
};


