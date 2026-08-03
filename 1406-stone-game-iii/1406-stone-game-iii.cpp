// class Solution {
// public:
//     int maxforAlice(vector<int> &stoneValue,int n,  int person , int i  , vector<vector<vector<int>>> &t, int j )
//     {
//         if(i>=n) return 0;
        
//         if(t[person][i][j] != INT_MIN) return t[person][i][j];

//         int result = (person == 1)? INT_MIN: INT_MAX;

//         int stones = 0;

//         for(int x = 1 ; x <= min( (n-i) , 3); x++)
//         {
//             stones += stoneValue[i+x-1];
            
//             if(person == 1)
//              result = max(result, stones + maxforAlice(stoneValue, n, 0, i+x, t ,x) );

//              else if(person == 0)
//              result = min(result,          maxforAlice(stoneValue, n, 1, i+x, t ,x) );

//         }

//     return t[person][i][j]= result;

//     }
//     string stoneGameIII(vector<int>& stoneValue) {
        
//         int n = stoneValue.size();
        
//         int person = 1;
//         int i =0;
//         int j=1;

//             vector<vector<vector<int>>> t(2, vector<vector<int>>(n, vector<int>(4, INT_MIN)));


//         int alice =  maxforAlice(stoneValue,n, person, i, t, j);

//         int sum =0;
//         for(int i=0; i<n; i++)
//         {
//             sum += stoneValue[i];
//         }

//         if(alice > sum-alice)
//         return "Alice";

//         else if(alice == sum-alice)
//         return "Tie";

//     return "Bob";
//     }
// };



class Solution {
public:
    int n;
    vector<int> t;

    int difference( vector<int> & stoneValue, int i)
    {
        if(i>= n) return 0;

         
        if(t[i] != -1) return t[i];
        

        int diff =  stoneValue[i] - difference(stoneValue, i+1);

        if(i+1<n)
        diff = max(diff , stoneValue[i] + stoneValue[i+1]  - difference(stoneValue, i+2));

        if(i+2<n)
        diff = max(diff , stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - difference(stoneValue, i+3));


        return t[i]=diff;

    }
    string stoneGameIII(vector<int>& stoneValue) {
        
         n = stoneValue.size();
         t.resize(n+1, -1);
         int diff = difference(stoneValue, 0);

         if(diff < 0) return "Bob";
         else if(diff > 0) return "Alice";

        return "Tie";
    }
};