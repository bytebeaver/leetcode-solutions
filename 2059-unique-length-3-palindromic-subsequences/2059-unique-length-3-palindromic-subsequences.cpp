class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        int n = s.length();

        unordered_set<char>letters;//to store all the unique letters present in the string

        for(int i=0; i<n; i++)
        {
            letters.insert(s[i]);
        }

        int result = 0 ;

        //we will give chance to each letter in the unordered set to see if it can be used to make a pallindrome
        //like in example aabca
        //the set 'letters' willl contain (a,b,c)
        //firstly we will give 'a' the chance to see if it can make a 3 letter pallindrome
        //like a_a from the available alphabets in string
        //we can see that yes we can make aba and aca

        for(char letter:letters)
        {
            //suppose letter is 'a'
            //now to see if the letter at hand can make a 3 letter pallindrome or not we will take:
            //its left most index in the string given and its right_most index in the string given 

            int left_index=-1;
            int right_index=-1;

            for(int i=0; i<n; i++)
            {

                if(s[i] == letter)
                {
                    if(left_index==-1)
                    left_index=i;

                    right_index=i;
                }
            }

            //now we have got the left most and right most index of letter at hand 
            //now we will all the unique characters in between these indexes
            //example in aabca left most index of a is 0 and right most index of a is 4 and all the unique characters between them are :
            //a,b,c hence we can make aba aca and aaa

            //storing all the unique characters between left most and right most index using set 
            unordered_set<char>st;

            for(int middle=left_index+1; middle<=right_index-1;middle++)
            {
                st.insert(s[middle]);
            }

            result+=st.size();
        }

        return result;
    }
};