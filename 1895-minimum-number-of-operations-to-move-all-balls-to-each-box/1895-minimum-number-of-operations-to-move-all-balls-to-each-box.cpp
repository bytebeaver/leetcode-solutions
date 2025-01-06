class Solution {
public:

    
    vector<int> minOperations(string boxes) {
      
      int n = boxes.size();
      vector<int>answer(n,0);

      int cummulative_value = 0;
      int cummulative_value_sum = 0;

      //find moves for shifting all balls to index i that lie on the left of index i
      for(int i=0; i<n; i++)
      {
        answer[i] = cummulative_value_sum;

        if(boxes[i] == '0')
        {
            cummulative_value += 0;
        }
        else{
        cummulative_value += 1;
        }

        cummulative_value_sum += cummulative_value;
      }

      cummulative_value = 0;
      cummulative_value_sum = 0;

      //find moves for shifting all balls to index i that lie on the  of right of index i
      for(int i=n-1; i>=0; i--)
      {
        answer[i] += cummulative_value_sum;

        if(boxes[i]=='0')
        {
            cummulative_value += 0;
        }
        else{
        cummulative_value += 1;
        }

        cummulative_value_sum += cummulative_value;
      }

      return answer;
    }
};



// class Solution {
// public:

//     //brute force approach 1
//     vector<int> minOperations(string boxes) {
//         int n = boxes.length();
//         vector<int>answer(n,0);

//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<n ;j++)
//             {
//                 if(boxes[j]=='1')
//                 answer[i]+=abs(j-i);
//             }
//         }

//         return answer;
//     }
// };