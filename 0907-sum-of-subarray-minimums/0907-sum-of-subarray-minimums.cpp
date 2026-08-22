class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        int M = 1e9 + 7;
        //getting previous smaller element  index array 
        vector<int> pse_idx(n);

        stack<int> st;

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

            if(st.empty())
            pse_idx[i] = -1;

            else
            pse_idx[i] = st.top();

            st.push(i);
        }

       //getting  Next smaller element's index array
        while(!st.empty())
        st.pop();

        vector<int> nse_idx(n);

        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty()  && arr[st.top()] > arr[i])
            st.pop();

            if(st.empty())
            nse_idx[i] = n;

            else
            nse_idx[i] = st.top();

            st.push(i);
        }


        //calculating contribution of each element in the output 

        long long sum =0;

        for(int i=0; i<n ; i++)
        {
            int index_of_PSE = pse_idx[i];
            int index_of_NSE = nse_idx[i];

            int num = (i - index_of_PSE) * (index_of_NSE - i);

            long long contribution = (long long)arr[i] * num;

            sum = (sum + contribution) % M;
        }

    return sum;
    }
};