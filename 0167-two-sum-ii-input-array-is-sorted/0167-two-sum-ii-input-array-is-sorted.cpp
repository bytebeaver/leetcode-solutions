class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
            int size=numbers.size();

            int i=0;
            int j=size-1;
            vector<int>result;

            while(i<=j)
            {
                if(numbers[i]+numbers[j]==target)
                {
                    result.push_back(i+1);
                    result.push_back(j+1);
                    return result;
                }

                else if(numbers[i]+numbers[j]<target)
                i++;

                else if(numbers[i]+numbers[j]>target)
                j--;
            }

        return result;
    }
};