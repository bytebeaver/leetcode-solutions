class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int n = pushed.size();

        // Simulate the actual stack operations.
        stack<int> st;

        // i -> next element to push
        // j -> next element that we need to pop
        int i = 0;
        int j = 0;

        while(i < n)
        {
            // Push the next element according to the
            // given pushed sequence.

            st.push(pushed[i]);

            /*If the top of the stack is the next element
             required by popped, we can safely pop it.
             Keep doing this because after popping one element,
             another element may also become available.*/ 

             
            while(!st.empty() &&
                  j < n &&
                  st.top() == popped[j])
            {
                st.pop();
                j++;
            }

            i++;
        }

        // If the stack is empty, every element was successfully
        // popped in the required order.
        return st.empty();
    }
};