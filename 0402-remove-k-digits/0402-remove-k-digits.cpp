class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.length();
        
        stack<char> st;

        int i = 0;

        while(i < n)
        {
            while(!st.empty() && num[i] < st.top() && k > 0)
            {
                st.pop();
                k--;
            }

            st.push(num[i]);
            i++;
        }

        // If k digits are still left to remove,
        // remove them from the end.
        while(k > 0)
        {
            st.pop();
            k--;
        }

        string output = "";

        while(!st.empty())
        {
            output.push_back(st.top());
            st.pop();
        }

        reverse(output.begin(), output.end());

         int pos = 0;

         while(pos<output.size()  && output[pos] == '0')
         pos++;

         output = output.substr(pos);

         if(output.empty())
         return "0";

         return output;
    }
};