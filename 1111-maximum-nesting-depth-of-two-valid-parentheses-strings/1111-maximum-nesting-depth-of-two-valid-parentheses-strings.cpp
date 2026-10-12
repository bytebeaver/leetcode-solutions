class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        
        int d = 0;
        vector<int> result(seq.length());
        for(int i=0; i<seq.length(); i++)
        {
            if( seq[i] == '(')
            {
                d++;
                result[i] =( d%2 == 0)?0:1;
            }
            else if( seq[i] == ')' )
            {
                result[i] = (d%2==0)?0:1;
                d--;
            }
        }
     return result;
    }
    
};