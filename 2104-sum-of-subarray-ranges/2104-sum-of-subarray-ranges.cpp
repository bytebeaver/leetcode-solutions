class Solution {
public:


    vector<int> getPSEidx(vector<int> &nums)
    {
        int n = nums.size();

        stack<int> st;
        vector<int> pse_idx(n);

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            st.pop();

            if(st.empty())
            pse_idx[i] = -1;

            else 
            pse_idx[i] = st.top();

            st.push(i);
        }

        return pse_idx;
    }

    vector<int> getNSEidx(vector<int> &nums)
    {
        int n = nums.size();

        stack<int> st;
        vector<int> nse_idx(n);

        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && nums[st.top()] > nums[i])
            st.pop();

            if(st.empty())
            nse_idx[i] = n;

            else 
            nse_idx[i] = st.top();

            st.push(i);
        }

        return nse_idx;
    }

    vector<int> getPGEidx(vector<int> &nums)
    {
        int n = nums.size();

        stack<int> st;
        vector<int> pge_idx(n);

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && nums[st.top()]<= nums[i])
            st.pop();

            if(st.empty())
            pge_idx[i] = -1;

            else 
            pge_idx[i] = st.top();

            st.push(i);
        }

        return pge_idx;
    }

    vector<int> getNGEidx(vector<int> &nums)
    {
        int n = nums.size();

        stack<int> st;
        vector<int> nge_idx(n);

        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && nums[st.top()]< nums[i])
            st.pop();

            if(st.empty())
            nge_idx[i] = n;

            else 
            nge_idx[i] = st.top();

            st.push(i);
        }

        return nge_idx;
    }


    long long minSubarraySum(vector<int> & nums)
    {
        int n = nums.size();

        vector<int> pse_idx = getPSEidx(nums);
        vector<int> nse_idx = getNSEidx(nums);

        long long sum=0;
        for(int i=0; i<n; i++)
        {
            int idx_of_pse = pse_idx[i];
            int idx_of_nse = nse_idx[i];

            long long num_of_subarrays_with_i_element_as_min = (i - idx_of_pse) * (idx_of_nse - i);

            long long contribution_to_final_sum = 1LL * nums[i] *   num_of_subarrays_with_i_element_as_min;

            sum += contribution_to_final_sum;

        }

        return sum;
    }


    long long maxSubarraySum(vector<int> & nums)
    {
        int n = nums.size();

        vector<int> pge_idx = getPGEidx(nums);
        vector<int> nge_idx = getNGEidx(nums);

        long long sum=0;
        for(int i=0; i<n; i++)
        {
            int idx_of_pge = pge_idx[i];
            int idx_of_nge = nge_idx[i];

            long long num_of_subarrays_with_i_element_as_max = (i - idx_of_pge) * (idx_of_nge - i);

            long long contribution_to_final_sum = 1LL * nums[i] *   num_of_subarrays_with_i_element_as_max;

            sum += contribution_to_final_sum;

        }

        return sum;
    }

   
    long long subArrayRanges(vector<int>& nums) {
        
        int n = nums.size();

        long long minimum_subarrays_sum = minSubarraySum(nums);
        long long maximum_subarrays_sum = maxSubarraySum(nums);

        return maximum_subarrays_sum - minimum_subarrays_sum;

    }
};