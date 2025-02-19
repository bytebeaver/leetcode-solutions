class Solution {
 public:

    bool matches( string &pattern, string &num)
    {
        for(int i=0; i<pattern.length(); i++)
        {
            if(pattern[i]=='I' && num[i] > num[i+1])
            return false;

            if(pattern[i] =='D' && num[i] < num[i+1])
            return false;
        }

        return true;
    }
    


  string smallestNumber(string pattern) {
   
   int n = pattern.length(); //"IID" --> n=3
   string num =""; 

    for(int i = 1; i<=n+1; i++)
    {
        num.push_back(i + '0');// i+ '0' changes the integer i to char i
    }

    while(!matches(pattern, num))
    {
        //stl function to generate permutations in lexicographical order
        next_permutation(begin(num), end(num));
    }

    return num;
   
  }
};