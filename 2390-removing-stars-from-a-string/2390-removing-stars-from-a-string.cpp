// class Solution {
// public:
//     string removeStars(string s) {
        
//         int n = s.length();

//         // We use a stack because:
//         // Whenever we encounter '*', we need to remove
//         // the character immediately before it.
//         // The most recently added character is exactly
//         // what a stack gives us through pop().
//         stack<char> st;

//         int i = 0;

//         while(i < n)
//         {
//             // If current character is '*', remove the
//             // most recently added character.
//             //
//             // We check !st.empty() so that we don't try
//             // to pop from an empty stack.
//             if(!st.empty() && s[i] == '*')
//             {
//                 st.pop();
//                 i++;
//             }

//             else
//             {
//                 // Normal character:
//                 // Add it to the stack because it may
//                 // need to be removed by a future '*'.
//                 st.push(s[i]);
//                 i++;
//             }
//         }

//         // The stack contains the remaining characters,
//         // but in reverse order because stack follows LIFO.
//         string str = "";

//         while(!st.empty())
//         {
//             // Take the top character and add it to the string.
//             // Since we are removing from the top, the string
//             // will initially be constructed backwards.
//             str.push_back(st.top());
//             st.pop();
//         }

//         // Reverse to restore the original left-to-right order.
//         reverse(begin(str), end(str));

//         return str;
//     }
// };


// approach 2 ---in cpp string itself work as stack and has push_back() and pop_back()
class Solution {
public:
    string removeStars(string s) {
        
        int n = s.length();

        // We use 'result' as a stack.
        //
        // push_back() adds a character to the end.
        // pop_back() removes the last character.
        string result = "";

        int i = 0;

        while(i < n)
        {
            if(s[i] == '*')
            {
                // '*' means:
                // Remove the character immediately before it.
                //
                // Since result stores all previous characters,
                // the last character is exactly the one we need
                // to remove.
                result.pop_back();

                i++;
            }

            else
            {
                // Normal character:
                // Add it to result.
                result.push_back(s[i]);

                i++;
            }
        }

        return result;
    }
};