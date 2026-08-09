class Solution {
 public:
  vector<int> validSequence(string word1, string word2) {
   
   int n = word1.length();
   int m = word2.length();

   vector<int> rightHandsideMatch(n,0);
    
    int i=n-1;
    int j=m-1;

    int match =0;
   while(i>=0)
   {
        if(j>=0 && word1[i] == word2[j])
        {
            match++;
            rightHandsideMatch[i] = match;
            i--; j--;
        }

        else{
             rightHandsideMatch[i] = match;
             i--;
        }
    }


    i=0;
    j=0;
    vector<int> seq;
    bool changePower = true;
    while(i<n && j<m)
    {
        if(word1[i] == word2[j])
        {
            seq.push_back(i);
            i++;
            j++;
        }

        else if(word1[i] != word2[j])
        {   
        
            if(changePower &&  i!= n-1 && rightHandsideMatch[i+1] >= (m-1) - j) //can i write rightHandsideMatch[i+1] == (m-1) - j) because i thinl it cannot be greater  also since i is going upto n-1 and i am trying to access i+1 index should i take care of this condition as well 
            {
                //we can use the power ----and change the char in word1
                // word1[i] = word2[j]; ---this step is not necessary as we only need index

                seq.push_back(i);
                changePower = false;
                i++;
                j++;

            }

            else
            i++;
        }

    }

    return (j==m) ? seq : vector<int>();
    
  }
};