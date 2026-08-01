class Solution {
public:

    bool predict(vector<int> &nums, int p1, int p2, int i, int j, bool var)
    {
        if(i>j)
        {
            if(p1>=p2)
            return true;

            else
            return false;
        }

        bool temp1=false,temp2=false;
      
        if(var)
        {
                p1 = p1 + nums[i];
                bool v1=predict(nums, p1, p2, i+1, j, false);

                p1 = p1-nums[i] + nums[j];
                bool v2=predict(nums ,p1, p2, i, j-1, false);

                temp1=v1 || v2;
        }


        else
        {
           
                p2 = p2 + nums[i];
                bool v1=predict(nums, p1, p2, i+1, j, true);

                p2 = p2-nums[i] + nums[j];
                bool v2=predict(nums ,p1, p2, i, j-1, true);

                temp2=v1 && v2;
        }

        return  temp1 || temp2;
}
    

    bool predictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        int p1=0;
        int p2=0;

        int i=0;
        int j=n-1;

        bool var = true;

        return predict(nums,p1, p2, i,j,var );
    }
};