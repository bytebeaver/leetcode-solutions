class Solution {
public:
    string removeStars(string s) {
        
        int n = s.length();

        stack<char>st;

        int i= 0;
        while(i<n)
        {
            if(!st.empty() && s[i] =='*')
            {
                st.pop();
                i++;
            }

            else
            {
                st.push(s[i]);
                i++;
            }
        }

        int stack_size = st.size();

        string str(stack_size, ' ');

        for(int i=stack_size-1; i>=0; i--)
        {
            str[i]= st.top();
            st.pop();
        }

    return str;
    }
};