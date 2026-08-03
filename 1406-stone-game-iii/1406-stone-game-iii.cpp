class Solution {
public:
    int n;
    vector<int> t;  // memo: t[i] = best (currentPlayer - otherPlayer) diff starting from index i

    int difference(vector<int> &stoneValue, int i)
    {
        // saare stones utha liye -> koi score contribute nahi hoga
        if (i >= n) return 0;

        // already computed hai to seedha return karo
        if (t[i] != -1) return t[i];

        // option 1: sirf 1 stone lo
        // apna gain - (baaki game mein opponent jo best diff nikaalega)
        int diff = stoneValue[i] - difference(stoneValue, i + 1);

        // option 2: 2 stones lo (sirf tabhi valid jab i+1 array ke andar ho)
        if (i + 1 < n)
            diff = max(diff, stoneValue[i] + stoneValue[i + 1] - difference(stoneValue, i + 2));

        // option 3: 3 stones lo (sirf tabhi valid jab i+2 array ke andar ho)
        if (i + 2 < n)
            diff = max(diff, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - difference(stoneValue, i + 3));

        // best diff store karo aur return karo
        return t[i] = diff;
    }

    string stoneGameIII(vector<int>& stoneValue)
    {
        n = stoneValue.size();
        t.resize(n + 1, -1);   // n+1 size taaki i == n (base case) bhi safely fit ho

        // Alice pehle move leti hai (i=0), so diff(0) = Alice's score - Bob's score
        int diff = difference(stoneValue, 0);

        if (diff > 0) return "Alice";
        else if (diff < 0) return "Bob";

        return "Tie";
    }
};