class Solution {
public:

    class BIT {
    public:

        int n;
        vector<int> bit;

        BIT(int n) {
            this->n = n;
            bit.resize(n + 1, 0);
        }

        void update(int i, int delta) {

            while (i <= n) {

                bit[i] += delta;

                i += i & (-i);
            }
        }

        int query(int i) {

            int sum = 0;

            while (i > 0) {

                sum += bit[i];

                i -= i & (-i);
            }

            return sum;
        }
    };


    int numTeams(vector<int>& rating) {

        int n = rating.size();


        // ---------- COORDINATE COMPRESSION ----------

        vector<int> vals = rating;

        sort(vals.begin(), vals.end());

        for (int &x : rating) {

            x = lower_bound(
                    vals.begin(),
                    vals.end(),
                    x
                ) - vals.begin() + 1;
        }


        // ---------- TWO BITs ----------

        BIT leftBIT(n);
        BIT rightBIT(n);


        // Initially all elements are on RIGHT

        for (int x : rating) {

            rightBIT.update(x, 1);
        }


        int ans = 0;


        // ---------- PROCESS EACH MIDDLE ELEMENT ----------

        for (int j = 0; j < n; j++) {

            int x = rating[j];


            // Remove current element from RIGHT

            rightBIT.update(x, -1);


            // ---------- LEFT ----------

            int leftSmaller =
                leftBIT.query(x - 1);

            int leftGreater =
                j - leftSmaller;


            // ---------- RIGHT ----------

            int rightSmaller =
                rightBIT.query(x - 1);

            int rightCount =
                n - j - 1;

            int rightGreater =
                rightCount - rightSmaller;


            // ---------- COUNT TEAMS ----------

            ans += leftSmaller * rightGreater;

            ans += leftGreater * rightSmaller;


            // Current element moves to LEFT

            leftBIT.update(x, 1);
        }


        return ans;
    }
};