class Solution {
public:
    typedef pair<char, int> P;

    struct lambda{
        bool operator()(P &p1, P &p2)
        {
            return p1.second  < p2.second; //heap  =  top mein maximum frewuency wali entry hogi
        }
    };

    string frequencySort(string s) {
        
        priority_queue<P, vector<P>, lambda> pq;

        unordered_map<char, int> mp;

        //updated in map
        for(char &ch: s)
        {
            mp[ch]++;
        }

        //fill in heap from map
        for( auto &it : mp)
        {
            pq.push( {it.first, it.second});
        }


        string result="";

        while(! pq.empty())
        {
            P temp = pq.top();

            pq.pop();

            result += string( temp.second, temp.first);
        }

        return result;
    }
};