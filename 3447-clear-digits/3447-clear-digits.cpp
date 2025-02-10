//Code story with MIK

// class Solution {
// public:

    // approach 1 brute force  ---- T.C -> O(N^2)

//     string clearDigits(string s) {
        
//         int i=0;
//         while(i<s.length() )
//         {
//             if( isdigit( s[i] ) )
//             {
//                 s.erase(i,1);
//                 if(i-1>=0)
//                 {
//                     s.erase(i-1,1);
//                     i--;
//                 }
//             }
//             else
//             i++;
//         }
//         return s;
//     }
// };


// class Solution {
// public:

    //Approach 2 ---> using stack 
                    //S.C -> O(N)
                    //T.C -> O(N)

//     string clearDigits(string s) {
        
//         stack <char> st;

//         for(char &ch : s)
//         {
//             if( isdigit( ch ) )
//             {
//                 if( !st.empty() )
//                 {
//                     st.pop();
//                 }
//             }
//             else
//             st.push( ch );
//         }

//         string result = "";
//         while(!st.empty() )
//         {
//             result.push_back( st.top() );
//             st.pop();
//         }

//         reverse(begin(result), end(result));
//         return result;
//     }
// };



// class Solution {
// public:

    //Approach 3---> using another empty string
                    //S.C -> O(N)
                    //T.C -> O(N)

// string clearDigits(string s) {
        
//         string result="";

//         for(char &ch : s)
//         {
//             if( isdigit( ch ) )
//             {
//                if(!result.empty())
//                {
//                 result.pop_back();

//                }
//             }
//             else
//             result.push_back( ch );
//         }

        
//         return result;
//     }
// };



class Solution {
public:

    //Approach 4--->  
                    //S.C -> O(1)
                    //T.C -> O(N)

    string clearDigits(string s) {
        
        int n = s.length();

        int i=0,j=0;

        while(i<n)
        {
            if( isdigit( s[i] ) )
            {   
                j=max(j-1, 0); // to prevent j from going negative
                // j--;//in future if i finds a valid character we will put it at jth index
            }

            else
            {
                s[j]=s[i];
                j++;
            }

            i++;
        }

    return s.substr(0, j);

    }
};



