#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // State struct: har "possibility" (no_delete ya one_delete) ka snapshot store karta hai
    // 3 fields ek saath group kiye hain taaki copy/assign karna easy ho (ek unit ki tarah)
    struct State {
        int sum;      // is state tak ka best possible sum
        int start;    // subarray kahan se start hota hai (reconstruction ke liye zaroori)
        int del_idx;  // kaunsa index delete hua (-1 agar koi deletion nahi hua is state mein)
    };

    // Result struct: final answer return karne ke liye
    // isme poora subarray (deleted element included) aur uska exclude index dono hote hain
    struct Result {
        vector<int> subarray;   // poora range ka subarray, deleted element bhi shaamil
        int excludeIndex;       // is index (subarray ke andar, relative) ko ignore karo, -1 = koi deletion nahi
    };

    Result maximumSum(vector<int>& arr) {
        int n = arr.size();

        // ---- BASE CASE ----
        // agar array mein sirf ek element hai, to deletion possible hi nahi
        // (subarray empty nahi ho sakta, isliye delete karne ka option nahi)
        if (n == 1)
            return { {arr[0]}, -1 };

        // ---- INITIALIZATION (index 0 ke liye) ----

        // no_delete: abhi tak koi deletion nahi hua, best sum sirf arr[0] hai
        // start = 0 kyunki subarray yahin se shuru ho raha hai
        // del_idx = -1 kyunki ye "no delete" state hai by definition
        State no_delete = {arr[0], 0, -1};

        // one_delete: INVALID state hai abhi kyunki ek hi element hai
        // agar isko delete kar diya to subarray empty ho jayega, jo allowed nahi
        // isliye INT_MIN diya taaki ye kabhi max() comparison mein jeet na paye
        State one_delete = {INT_MIN, -1, -1};

        // global best tracker — poore loop mein "ab tak ka sabse best answer" record karta hai
        // shuru mein no_delete ki values se copy kiya kyunki one_delete abhi invalid hai
        int best_sum = arr[0];
        int best_start = 0;
        int best_end = 0;
        int best_del_idx = -1;   // -1 matlab koi deletion involved nahi hai best answer mein

        // ---- MAIN LOOP: index 1 se n-1 tak ----
        for (int i = 1; i < n; i++) {

            // update karne se PEHLE purani (i-1 wali) values safe copy mein bacha lo
            // taaki aage calculation karte waqt galti se "naye update ho chuke" values use na ho
            State prev_no_del = no_delete;
            State prev_one_del = one_delete;

            // ================= ONE_DELETE UPDATE =================
            if (i == 1) {
                // SPECIAL CASE: kyunki prev_one_del (index 0 ka one_delete) invalid tha (INT_MIN)
                // normal formula (prev_one_del.sum + arr[i]) use karne se garbage value milegi
                // isliye manually socho: sirf arr[0], arr[1] hain, ek delete karna hai

                int optA = arr[1];             // matlab arr[0] ko delete kiya, sirf arr[1] bacha
                int optB = prev_no_del.sum;    // matlab arr[1] ko delete kiya, sirf arr[0] (=prev_no_del.sum) bacha

                if (optA >= optB)
                    one_delete = {optA, 0, 0};   // arr[0] delete hua, start=0, del_idx=0
                else
                    one_delete = {optB, 0, 1};   // arr[1] delete hua, start=0, del_idx=1

            } else {
                // NORMAL CASE: do choices hain current element arr[i] ke liye

                int optA = prev_one_del.sum + arr[i];  
                // Choice A: deletion PEHLE HI ho chuka tha, ab bas current element ko extend karo

                int optB = prev_no_del.sum;            
                // Choice B: abhi is current index i ko DELETE kar rahe hain (isliye arr[i] add nahi hua)

                if (optA >= optB)
                    // Choice A jeeta: start aur del_idx same rahenge (purana deletion hi continue ho raha hai)
                    one_delete = {optA, prev_one_del.start, prev_one_del.del_idx};
                else
                    // Choice B jeeta: start prev_no_del wala liya, del_idx = i (yahi naya deletion hai)
                    one_delete = {optB, prev_no_del.start, i};
            }

            // ================= NO_DELETE UPDATE (Plain Kadane's) =================
            int optA = arr[i];                      // fresh restart yahin se (agar purana sum negative/nuksaan wala tha)
            int optB = prev_no_del.sum + arr[i];     // purane subarray ko extend karo (agar purana sum helpful tha)

            if (optB >= optA)
                no_delete = {optB, prev_no_del.start, -1};  // extend: start same rahega
            else
                no_delete = {optA, i, -1};                  // restart: naya start = i

            // del_idx hamesha -1 rahega yahan kyunki ye "no delete" state hai — kabhi deletion nahi hota isme

            // ================= GLOBAL BEST UPDATE =================
            // har iteration mein check karo — kya abhi ka no_delete ya one_delete
            // ab tak ke best se bhi zyada acha hai? Agar haan, to best ki saari fields update karo
            if (no_delete.sum > best_sum) {
                best_sum = no_delete.sum;
                best_start = no_delete.start;
                best_end = i;              // best_end = i kyunki abhi tak ka subarray i tak consider ho raha hai
                best_del_idx = -1;         // no_delete se aaya hai, isliye koi deletion nahi
            }

            if (one_delete.sum > best_sum) {
                best_sum = one_delete.sum;
                best_start = one_delete.start;
                best_end = i;
                best_del_idx = one_delete.del_idx;  // jo bhi index delete hua tha, wahi carry hoga
            }
        }

        // ================= RECONSTRUCTION: poora subarray banao (deleted element included) =================
        vector<int> fullSubarray;
        int exclude_idx = -1;    // default -1, agar koi deletion nahi hua to yahi rahega

        for (int j = best_start; j <= best_end; j++) {
            // agar ye wahi index hai jo humne DP mein delete kiya tha,
            // to uska POSITION note kar lo — PUSH karne se PEHLE
            // (kyunki fullSubarray.size() abhi batata hai ki agla push hone wala element
            //  kis position par baithega — vector ki 0-based indexing ki wajah se)
            if (j == best_del_idx)
                exclude_idx = fullSubarray.size();

            // har element ko push karo — deleted wala bhi, SKIP nahi kar rahe
            // kyunki humein poora range chahiye, sirf "surviving elements" ki list nahi
            fullSubarray.push_back(arr[j]);
        }

        // final result return karo — poora subarray + jo index ignore karna hai
        return { fullSubarray, exclude_idx };
    }
};

int main() {
    Solution sol;

    // test array — dry run isi pe kiya tha
    vector<int> arr = {2, -5, 3, -1, 4, -6, 2, 8};

    Solution::Result res = sol.maximumSum(arr);   // :: isliye kyunki Result, Solution class ke andar nested hai

    cout << "Full subarray: [ ";
    for (int x : res.subarray) cout << x << " ";
    cout << "]" << endl;

    cout << "Exclude index: " << res.excludeIndex << endl;

    // verification — exclude index ko chhodke sum nikalo, best_sum se match hona chahiye
    int checkSum = 0;
    for (int i = 0; i < (int)res.subarray.size(); i++)
        if (i != res.excludeIndex)
            checkSum += res.subarray[i];

    cout << "Verification Sum: " << checkSum << endl;

    return 0;
}
