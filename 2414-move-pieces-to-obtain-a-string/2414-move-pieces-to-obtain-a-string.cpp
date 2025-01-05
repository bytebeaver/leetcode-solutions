class Solution {
public:
    bool canChange(string start, string target) {
        
        int n = start.length();

        int i=0; 
        int j=0;


        while(i<n || j<n)
        {
            while( i < n && start[i]=='_')
            {
                i++;
            }

            while( j < n && target[j]=='_')
            {
                j++;
            }

            if(i == n || j==n) {
                return i==n && j==n;
            }

            if(start[i] != target[j])
            return false;

            if(start[i] == 'L' && i<j /*we cant move L cuz i is less than j and it will never reach j cuz L is not allowed to swap right side*/)
            {
                return false;
            }

            if(start[i] == 'R' && i>j /*we cant move R cuz i is greater than j and it will never reach j cuz R is not allowed to swap left side*/)
            {
                return false;
            }

            //koi rule violate nahi hua
            i++;
            j++;
        }

        return true;
    }
};