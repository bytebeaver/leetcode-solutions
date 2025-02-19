
//CODESTORY WITH MIK

//BRUTE FORCE : USING STL
//1) generate the lexicograpgically smallest string num
//2) check if it follows the condition according to the given pattern 


// class Solution {
//  public:


//     bool matches( string &pattern, string &num)
//     {
//         for(int i=0; i<pattern.length(); i++)
//         {
//             if(pattern[i]=='I' && num[i] > num[i+1])
//             return false;

//             if(pattern[i] =='D' && num[i] < num[i+1])
//             return false;
//         }

//         return true;
//     }
    


//   string smallestNumber(string pattern) {
   
//    int n = pattern.length(); //"IID" --> n=3
//    string num =""; 

//     //the lexicographically smallest string num is : "123456....n"
//     for(int i = 1; i<=n+1; i++)
//     {
//         num.push_back(i + '0');// i+ '0' changes the integer i to char i
//     }

//     while(!matches(pattern, num))
//     {
//         //stl function to generate permutations in lexicographical order
//         next_permutation(begin(num), end(num));
//     }

//     return num;
   
//   }
// };

//APPROACH 2---> Using Stack


class Solution {
 public:

  string smallestNumber(string pattern) {
    int n = pattern.length();

    int counter = 1;
    stack<char> st;

    string num ="";

    for(int i=0; i<=n; i++)
    {
        st.push(counter + '0');
        counter++;

        if(i==n || pattern[i]=='I')
        {
           while(!st.empty())
           {
            num += st.top();
            st.pop();
           }
        }
    }

    return num;
  }
};


