class Solution {
public:
    string removeKdigits(string num, int k) {

        int n = num.length();

        // Stack stores the digits that we currently want to keep.
        // We try to keep the digits in increasing order.
        stack<char> st;

        int i = 0;

        while(i < n)
        {
            /*
                If the current digit is smaller than the digit
                at the top of the stack, removing the top digit
                will make the number smaller.

                Example:
                    stack top = 4
                    current   = 3

                Keeping 3 before 4 is better than keeping 4 before 3.

                We can keep removing previous larger digits while:
                1. Stack is not empty
                2. Current digit is smaller than stack.top()
                3. We still have digits available to remove
            */
            while(!st.empty() && num[i] < st.top() && k > 0)
            {
                st.pop();
                k--;
            }

            // Keep the current digit.
            st.push(num[i]);

            i++;
        }

        /*
            If k is still greater than 0, it means the number
            was already in increasing order (or no useful
            decreasing pair was left).

            In this situation, removing digits from the END
            gives the smallest possible number.

            Example:
                num = "123456", k = 2

                Remove 6 and 5
                Result = "1234"
        */
        while(k > 0)
        {
            st.pop();
            k--;
        }

        string output = "";

        /*
            Stack gives elements in reverse order.

            Example:
                Stack: 1 2 1 9

                Popping gives:
                9 1 2 1

            So we reverse the string afterwards.
        */
        while(!st.empty())
        {
            output.push_back(st.top());
            st.pop();
        }

        // Restore the original left-to-right order.
        reverse(output.begin(), output.end());


        /*
            Remove leading zeroes.

            Example:
                output = "0200"

                After removing leading zero:
                output = "200"
        */
        int pos = 0;

        while(pos < output.size() && output[pos] == '0')
        {
            pos++;
        }

        output = output.substr(pos);


        /*
            If all digits were zero, output becomes empty.

            Example:
                "000" -> "" after removing leading zeroes

            The integer representation should be "0".
        */
        if(output.empty())
            return "0";

        return output;
    }
};