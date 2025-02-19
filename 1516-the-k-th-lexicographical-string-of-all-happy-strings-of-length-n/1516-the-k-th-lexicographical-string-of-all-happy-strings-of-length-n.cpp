//CODESTORY WITH MIK

//BACKTRACKING
//1. DO
//2. TRY
//3. EXPLORE


// class Solution {
// public:


//     void solve(string &curr, vector<string> &result, int &n)
//     {
//         if(curr.size() == n)
//         {
//             result.push_back(curr);
//             return;
//         }

//         for(char ch='a' ; ch<='c';ch++)
//         {
//             if(!curr.empty() && curr.back() == ch)
//             continue;

//             //DO
//             curr.push_back(ch);

//             //EXPLORE
//             solve(curr, result, n);

//             //UNDO
//             curr.pop_back();
            
//         }
//     }
//     string getHappyString(int n, int k) {
        
//         string curr = "";

//         vector<string> result;

//         solve(curr, result, n);

//         if(result.size() < k)
//         return "";

//         return result[k-1];

//     }
// };



// OPTIMZED APPROACH ---- same backtracking but we dont need o store all the sequences in result
class Solution {
public:


    void solve(string &curr, string &result, int &n, int &counter, int &k)
    {
        if(curr.size() == n)
        {
            // result.push_back(curr);
            counter++;
            if(counter == k)
            {
                result = curr;
            }
            return;
        }

        for(char ch='a' ; ch<='c';ch++)
        {
            if(!curr.empty() && curr.back() == ch)
            continue;

            //DO
            curr.push_back(ch);

            //EXPLORE
            solve(curr, result, n, counter , k);

            //UNDO
            curr.pop_back();
            
        }
    }
    string getHappyString(int n, int k) {
        
        string curr = "";

        string result="";
        int counter=0;

        solve(curr, result, n, counter, k);

      

        return result;

    }
};