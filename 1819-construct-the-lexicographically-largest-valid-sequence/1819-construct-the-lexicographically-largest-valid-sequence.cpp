class Solution {
public:

    bool solve(int i, int n, vector<int> &result, vector<bool> &used)
    {
        if(i>= result.size())
        {
            return true; //guaranteeed becasue we were trying to put the largest number firstly, if we have reached here it means all the numbers are put accordingly
        }

        if(result[i] != -1)
        {
            return solve(i+1, n, result, used);
        }

        for(int num = n; num>=1; num--)
        {
            if(used[num] == true)
            {
                continue;
            }

            //TRY
            used[num] = true;
            result[i]=num;

            //EXPLORE
            if(num==1)
            {
                if( solve(i+1, n, result, used) == true )
                return true;
            }
            else
                {
                    int j=result[i]+i;

                    if(j<result.size() && result[j]==-1)
                    {
                        result[j] = num;

                        if(solve(i+1, n, result, used) == true)
                        {
                            return true;
                        }
                        //agar true nahi return hua to we have to undo the changes that we did at index j
                        result[j]=-1;
                    }

                }

            //UNDO THE CHANGES TO i ----> P.S-->we are still inside the loop ...so don't be confused
            //we are undoing these changes because  in this above --> if(j<result.size() && result[j]==-1) , either one of the condition has failed 
            //OR
            //this -->  if(j<result.size() && result[j]==-1) , has passed but then further true was not returned and we did result[j] = -1
            result[i]=-1;
            used[num]=false;
        }

        return false;
    }



    vector<int> constructDistancedSequence(int n) {
        
        vector <int> result(2*n-1, -1);

        vector<bool> used(n+1, false);

        solve(0, n, result, used);

        return result;
    }
};