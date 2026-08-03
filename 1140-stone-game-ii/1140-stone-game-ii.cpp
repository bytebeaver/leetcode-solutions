class Solution {
public:

    int t[2][101][101];

    int maxforAlice(vector<int> &piles,int n,  int person , int i , int M )
    {
        if(i>=n) return 0;
        
        if(t[person][i][M] != -1) return t[person][i][M];

        int result = (person == 1)? -1: INT_MAX;

        int stones = 0;

        for(int x = 1 ; x <= min( (n-i) , 2*M); x++)
        {
            stones += piles[i+x-1];
            
            if(person == 1)
             result = max(result, stones + maxforAlice(piles, n, 0, i+x, max(M,x) ) );

             else if(person == 0)
             result = min(result,          maxforAlice(piles, n, 1, i+x, max(M,x) ) );

        }

    return t[person][i][M]= result;

    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int M = 1;
        int person = 1;
        int i =0;

        memset(t, -1, sizeof(t) );


        return maxforAlice(piles,n, person, i, M);
    }
};