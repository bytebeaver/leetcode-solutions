class Solution {
 public:
  vector<int> validSequence(string word1, string word2) {

    int n = word1.length();   // n = word1 ki length. Example: word1="aebbd" -> n=5
    int m = word2.length();   // m = word2 ki length. Example: word2="abcd"  -> m=4

    // rightHandsideMatch[i] = "word1[i..n-1]" use karke word2 ke KITNE trailing
    // characters (end se) exact subsequence match ho sakte hain.
    // Example (word1="aebbd", word2="abcd") -> rightHandsideMatch = [1,1,1,1,1]
    // (matlab har index se aage sirf 'd' hi match ho pa raha hai, 1 char)
    vector<int> rightHandsideMatch(n, 0);

    int i = n - 1;   // i = word1 ka backward pointer, end se start karta hai
    int j = m - 1;   // j = word2 ka backward pointer, end se start karta hai

    int match = 0;   // match = ab tak backward matching mein kitne characters mile

    // ---- PASS 1: Suffix precompute (backward) ----
    while (i >= 0) {
        if (j >= 0 && word1[i] == word2[j]) {
            match++;                          // ek naya match mila, counter badhao
            rightHandsideMatch[i] = match;     // is index tak ka best match store karo
            i--; j--;                          // dono pointer peeche
        } else {
            rightHandsideMatch[i] = match;     // match nahi mila, purana count hi rakho
            i--;                               // sirf word1 ka pointer peeche
        }
    }

    // ---- PASS 2: Forward greedy matching ----
    i = 0;   // i = word1 ka forward pointer (0 se start)
    j = 0;   // j = word2 ka forward pointer (0 se start)

    vector<int> seq;              // seq = final answer indices ki list
    bool changePower = true;      // changePower = "kya hamare paas abhi bhi 1 allowed change bacha hai?"
                                   // Example: shuru mein true, ek baar use hone ke baad false

    while (i < n && j < m) {
        if (word1[i] == word2[j]) {
            // Case A: exact match mil gaya -> greedily le lo (lexicographically smallest ke liye best)
            seq.push_back(i);
            i++;
            j++;
        }
        else {


            // Case B: mismatch. Check karo power use karna safe hai ya nahi.
            // BUG-AWARE VERSION: `i+1 < n` bounds check yahan add kiya hai
            // (original code mein `i<n` likha tha jo galat guard hai, neeche
            // "Common Mistakes" section mein explain kiya hai)


            if (changePower && (i + 1 < n) && rightHandsideMatch[i + 1] >= (m - 1) - j) {
                // rightHandsideMatch[i+1] >= (m-1)-j ka matlab:
                // "agar main yahan power use karke aage badhoon, to bacha hua
                //  word2 ka portion (length = (m-1)-j) word1[i+1..n-1] se
                //  poora match ho jaayega" -> safe hai, power use karo


                seq.push_back(i);
                changePower = false;   // power khatam ho gayi, dobara use nahi hogi
                i++; j++;
            }
            
             else {
                // Power use karna safe nahi (ya already use ho chuki), skip karo
                i++;
            }
        }
    }

    // Agar j poora m tak pahuncha, to match complete hua, warna answer nahi bana
    return (j == m) ? seq : vector<int>();
  }
};