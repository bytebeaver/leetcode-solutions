class Solution {
public:

    bool isVowel(char &ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' ||ch=='o' || ch=='u')
        return true;
    
    return false;
    }


    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        int Q = queries.size();
        int N = words.size();

        vector<int>result(Q);

        vector<int>cummulative_sum(N);

        int sum=0;//number  of strings that have front and last character as vowel

        for(int i=0; i<N; i++)
        {
            if(isVowel( words[i][0] )  &&  isVowel( words[i].back() )  )
            sum++;

            cummulative_sum[i]=sum;
        }

        for(int i=0; i<Q; i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];

            if(l!=0)
            {
                result[i] = cummulative_sum[r] - cummulative_sum[l-1];
            }

            else
            {
                result[i] = cummulative_sum[r] - 0;
            }
        }

        return result;
    }
};