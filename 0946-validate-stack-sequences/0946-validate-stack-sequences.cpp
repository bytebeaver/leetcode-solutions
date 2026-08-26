class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int m = pushed.size();

        stack<int> st;

        int i=0;
        int j=0;

        while(i<m && j<m)
        {
            st.push(pushed[i]);

            while(!st.empty() && st.top() == popped[j] && j<m)
            {
                st.pop();
                j++;
            }

        i++;
        }

        if(st.empty())
        return true;

    return false;
    }
};