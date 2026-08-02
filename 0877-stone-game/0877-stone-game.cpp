// class Solution {
// public:

//      bool winner(vector <int> piles,int alice,int bob ,int  i,int j, bool var)
//     {
//         if(i>j)
//         {
//             if(alice > bob)
//             return true;

//             else 
//             return false;
//         }

//         bool temp1 = false;
//         bool temp2 = false;

//         if(var)
//         {   
//             alice = alice + piles[i];
//             bool v1 =  winner(piles, alice, bob , i+1,j, false);

//             alice = alice - piles[i] + piles[j];
//             bool v2 =  winner(piles, alice, bob , i,j-1, false);

//             temp1 = v1 || v2;

//         }

//         else
//         {
//             bob = bob + piles[i];
//             bool v1 =  winner(piles, alice, bob , i+1,j, true);

//             bob = bob - piles[i] + piles[j];
//             bool v2 =  winner(piles, alice, bob , i,j-1, true);

//             temp2 = v1 && v2;

//         }

//         return temp1 || temp2;
//     }




//     bool stoneGame(vector<int>& piles) {
        
//         bool var = true;
//         int alice = 0;
//         int bob = 0;
//         int i=0, j=piles.size()-1;

//         return winner(piles, alice, bob , i,j, var);
//     }
// };

class Solution {
 public:
  bool stoneGame(vector<int>& piles) {
    const int n = piles.size();
    // dp[i][j] := the maximum stones you can get more than your opponent in
    // piles[i..j]
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
      dp[i][i] = piles[i];

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        const int j = i + d;
        dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
      }

    return dp[0][n - 1] > 0;
  }
};