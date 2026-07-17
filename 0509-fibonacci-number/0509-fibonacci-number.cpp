/*
    ================================================================
    PROBLEM: Nth Fibonacci Number
    APPROACH USED: Top-Down Dynamic Programming (Memoization)
    ================================================================

    WHAT IS DP, REALLY?
    --------------------
    Dynamic Programming = Recursion + Remembering answers you've
    already calculated, so you never redo the same work twice.

    Think of it like this: if a friend asks you "what's 5+5?" ten
    times in a row, you don't recalculate it every time — you just
    remember "oh that's 10" and answer instantly. That's exactly
    what memoization does for recursive calls.

    WHY FIBONACCI NEEDS THIS
    -------------------------
    Plain recursion for fib(n) branches into fib(n-1) and fib(n-2).
    Those branch further, and you end up recalculating the SAME
    smaller Fibonacci values again and again (e.g. fib(2) might get
    computed hundreds of times inside fib(30)). This causes an
    exponential blow-up: O(2^n) time.

    Memoization fixes this by storing the result of each subproblem
    (each unique value of n) the FIRST time it's computed, in an
    array called "dp". Next time that same n is needed, we just
    look it up instead of recomputing — turning exponential time
    into linear time.

    THE 3 STEPS OF MEMOIZATION (this is the core pattern, memorize
    this shape — you'll use it in almost every DP problem):

    1) DECLARATION: Create a storage array (dp) big enough to hold
       an answer for every possible subproblem, initialized to a
       "not computed yet" sentinel value (here we use -1, since
       actual Fibonacci numbers are never negative).

    2) CHECKING: Before doing any real computation for a
       subproblem, check if dp[n] already has a real answer stored.
       If yes, return it immediately — this is what saves us time.

    3) STORAGE: After computing the answer for a subproblem for the
       first time, store it in dp[n] before returning, so future
       calls can reuse it.
    ================================================================
*/

#include <vector>
using namespace std;

class Solution {
public:

    // ----------------------------------------------------------
    // Helper function that does the actual recursive + memoized
    // computation. Takes 'n' (which Fibonacci number we want) and
    // a reference to the dp array (passed by reference so we don't
    // copy the whole array on every single recursive call — that
    // would be wasteful).
    // ----------------------------------------------------------
    int fibonacci(int n, vector<int> &dp)
    {
        // ---- BASE CASE ----
        // Fibonacci is defined as fib(0) = 0, fib(1) = 1.
        // This is where the recursion "bottoms out" and stops
        // calling itself further.
        if (n <= 1) return n;

        // ---- STEP 2: CHECKING ----
        // Before doing any fresh work, ask: "have I already solved
        // this exact subproblem before?"
        // dp[n] != -1 means YES, it's already been solved and
        // stored — so just hand back the stored answer instantly,
        // skipping recomputation entirely. This single check is
        // what collapses O(2^n) recursion down to O(n).
        if (dp[n] != -1) return dp[n];

        // ---- RECURSIVE RELATION ----
        // If we haven't solved it yet, break the problem into two
        // smaller subproblems (this is the actual Fibonacci
        // recurrence: fib(n) = fib(n-1) + fib(n-2)), solve those
        // recursively (they'll use their own memo checks too), and
        // combine their results.
        //
        // ---- STEP 3: STORAGE ----
        // Immediately store the freshly computed result in dp[n]
        // BEFORE returning. This is what future calls will find
        // and reuse in Step 2 above.
        dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);

        return dp[n];
    }

    int fib(int n)
    {
        // ---- STEP 1: DECLARATION ----
        // Create a dp array of size (n+1) — indices 0 through n —
        // so we have a slot to store the answer for every possible
        // subproblem from fib(0) up to fib(n).
        // Every slot starts as -1, meaning "not solved yet".
        vector<int> dp(n + 1, -1);

        // Kick off the recursion. This call will internally build
        // up dp[] from the smallest subproblems upward (even
        // though it LOOKS top-down, the base cases get hit first
        // as the recursion unwinds).
        return fibonacci(n, dp);
    }
};

/*
    ================================================================
    COMPLEXITY ANALYSIS
    ================================================================

    TIME COMPLEXITY: O(n)
    ----------------------
    Without memoization, plain recursive Fibonacci makes 2 calls
    per call, doubling roughly every level -> O(2^n), which is
    brutally slow (fib(40) alone would take billions of calls).

    WITH memoization: each value from 0 to n gets computed EXACTLY
    ONCE (thanks to the dp[n] != -1 check blocking repeat work).
    Once computed, every future request for that value is an O(1)
    array lookup. Since there are only (n+1) unique subproblems
    total, and each is solved once in O(1) work (excluding its
    recursive calls, which are themselves counted separately),
    total time = O(n).

    SPACE COMPLEXITY: O(n)
    ------------------------
    Two contributors, both linear in n:
      1) The dp array itself: size (n+1) -> O(n).
      2) The recursion call stack: in the worst case (going from
         fib(n) down to fib(1) via the fib(n-1) chain before ever
         hitting fib(n-2)), the stack can be n frames deep -> O(n).
    Combined, still O(n) overall (constants don't matter in Big-O).

    ================================================================
    INTUITION MAP: How this connects to DP as a general idea
    ================================================================
    - "Overlapping subproblems": fib(n-2) gets asked for by BOTH
      fib(n) directly and indirectly through fib(n-1)'s own call to
      fib(n-2)... wait, actually more precisely: fib(n-1) and
      fib(n) both eventually need fib(n-3), fib(n-4), etc. This
      overlap is WHY memoization helps at all — if every subproblem
      were only ever needed once, memoizing would save nothing.

    - "Optimal substructure": fib(n) is built purely from the
      answers to fib(n-1) and fib(n-2) — no other information is
      needed. This is what lets us define that clean recursive
      relation dp[n] = fib(n-1) + fib(n-2) in the first place.

    - This exact pattern (recursion + check dp + store in dp) is
      called TOP-DOWN DP / Memoization. Later you'll also learn
      BOTTOM-UP DP (Tabulation), where instead of recursing from n
      downward, you build dp[0], dp[1], ... dp[n] in a simple loop
      from the ground up. Same idea, opposite direction — worth
      trying to convert this solution into a loop-based version as
      practice once this feels solid.
    ================================================================
*/



// #include <vector>
// using namespace std;

// class Solution {
// public:
//     int fib(int n)
//     {
//         int prev1 = 1;  // represents fib(1)
//         int prev2 = 0;  // represents fib(0)

//         if (n == 0) return 0;

//         for (int i = 2; i <= n; i++)
//         {
//             int current = prev1 + prev2;  // fib(i)
//             prev2 = prev1;
//             prev1 = current;
//         }

//         return prev1;
//     }
// };


// Algorithm (Example ke saath samjhte hai)
// Ye approach iterative / bottom-up hai — hum chhote Fibonacci numbers se shuru karke bade tak build karte hai, aur sirf last do values ko yaad rakhte hai (poora array nahi).
// Chaliye n = 5 ka example lete hai:
// Step 1: Base values set karo
// prev2 = 0 (ye fib(0) hai), prev1 = 1 (ye fib(1) hai)
// Yaani hum already fib(0) aur fib(1) jaante hai, unse start karenge.
// Step 2: Loop chalao i=2 se n tak
// Har step pe naya fibonacci number banega = prev1 + prev2

// i=2: current = 1+0 = 1 (ye fib(2) hai) → ab prev2=1, prev1=1
// i=3: current = 1+1 = 2 (ye fib(3) hai) → ab prev2=1, prev1=2
// i=4: current = 2+1 = 3 (ye fib(4) hai) → ab prev2=2, prev1=3
// i=5: current = 3+2 = 5 (ye fib(5) hai) → ab prev2=3, prev1=5

// Step 3: Answer return karo
// Loop khatam hone ke baad prev1 hi answer hai → fib(5) = 5 ✓
// Idea simple hai: Fibonacci ke liye humesha sirf pichle do numbers chahiye hote hai, poori history nahi. Isliye array store karne ki zaroorat nahi — bas do variables (prev1, prev2) ghumate raho aur aage badhte raho.


// Complexity

// Time: O(n) — same as before, loop ek baar 2 se n tak chalta hai.
// Space: O(1) — pehle wale memoization solution me dp array O(n) space le raha tha. Yahan hum sirf do variables use kar rahe hai, chahe n kitna bhi bada ho, extra space fixed hi rahega. Isko space-optimized DP kehte hai.


// Kya ye DP hai?
// Haan, ye bhi DP hi hai — bas iska "state storage" alag tarike se ho raha hai.
// DP ka core idea ye hota hai: chhote subproblems ka answer use karke bade subproblem ka answer banao, taaki wahi cheez baar-baar calculate na karni pade. Ye tumhare is code me bhi ho raha hai — current = prev1 + prev2 likhna matlab tum fib(i-1) aur fib(i-2) ke already computed answers use kar rahe ho, dobara se recursion call karke nahi nikaal rahe.
// Farak sirf itna hai ki:

// Memoization wale version me tumne poora dp array rakha tha, taaki kisi bhi purane subproblem ka answer kabhi bhi lookup kar sako.
// Is version me tumhe pata hai ki fib(i) banane ke liye sirf fib(i-1) aur fib(i-2) chahiye — usse purana kuch bhi nahi chahiye. Isliye poora array rakhne ki zaroorat nahi, bas last do values rakhna kaafi hai.

// Ye ek common DP optimization pattern hai — jab tumhe pata ho ki current answer sirf pichle 1-2 states pe depend karta hai (poori history pe nahi), tab tum array ko chhote fixed-size variables se replace kar sakte ho. Isko "rolling array" ya "space-optimized DP" kaha jaata hai, aur ye recursion + memoization ka hi natural extension hai, sirf implementation zyada efficient hai.