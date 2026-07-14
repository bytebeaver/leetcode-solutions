/*
=====================================================================
ALGORITHM: Find Minimum in Rotated Sorted Array (Binary Search)
=====================================================================

WHAT IS A "ROTATED SORTED ARRAY"?
A normally sorted array like [1,2,3,4,5] gets "rotated" at some pivot
point, e.g. [4,5,1,2,3]. We need to find the smallest element in
O(log n) time (not O(n), so no simple linear scan allowed).

KEY INSIGHT:
At any point during binary search, the window [low...mid...high]
is split into two halves. AT LEAST ONE of these halves is always
"properly sorted" (no rotation break inside it). The other half
either contains the rotation point, or is also sorted if there's
no rotation left in the window at all.

So at every step we ask: "Is the LEFT half (low to mid) sorted?"

  -> If YES (nums[mid] >= nums[low]):
       - The minimum can't be "hiding" deeper inside this sorted
         left half, because in a sorted stretch the FIRST element
         (nums[low]) is already the smallest of that stretch.
       - So we record nums[low] as a candidate for the overall min.
       - Then we discard this entire left half (it's already been
         accounted for) and move our search to the right half.

  -> If NO, i.e. nums[mid] <= nums[high]:
       - This means the right half (mid to high) is the sorted one
         instead (since left wasn't sorted, the break/seam is inside
         the left half, or right half stands sorted on its own).
       - nums[mid] is the smallest value in this sorted right half.
       - Record nums[mid] as a candidate.
       - Discard the right half, move search to the left half.

We keep halving the search window like this until low > high,
tracking the smallest candidate seen so far (mini). That's the answer.

Think of it like hunting for the "seam" where the array wraps
around. Whichever half is properly sorted, its first element IS
that half's minimum — bank it, throw that half away, and keep
zooming into the other (possibly-broken) half where the seam,
and the true global minimum, must be lurking.

=====================================================================
WORKED EXAMPLE: nums = [4, 5, 6, 7, 0, 1, 2]
(this is [0,1,2,4,5,6,7] rotated)

Indices:   0:4   1:5   2:6   3:7   4:0   5:1   6:2

STEP 1: low=0, high=6, mid=3
   nums[mid]=7, nums[low]=4  ->  Is 7 >= 4? YES (left half sorted)
   mini = min(INT_MAX, nums[0]=4) = 4
   low = mid+1 = 4   (throw away left half, search right)

STEP 2: low=4, high=6, mid=5
   nums[mid]=1, nums[low]=0  ->  Is 1 >= 0? YES (left half sorted)
   mini = min(4, nums[4]=0) = 0
   low = mid+1 = 6   (throw away left half, search right)

STEP 3: low=6, high=6, mid=6
   nums[mid]=2, nums[low]=2  ->  Is 2 >= 2? YES (left half sorted)
   mini = min(0, nums[6]=2) = 0
   low = mid+1 = 7   (throw away left half, search right)

LOOP CHECK: low(7) <= high(6)? NO -> exit loop

RETURN mini = 0   ✅ correct! (0 is indeed the minimum)

NOTE: Even if the array has NO rotation at all (already fully
sorted), nums[mid] >= nums[low] will just keep being true every
time, and low will keep climbing until nums[low] itself becomes
the true minimum — so the same logic naturally handles that case too.
=====================================================================
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int low = 0;                   // left boundary of current search window
        int high = nums.size() - 1;    // right boundary of current search window
        int mini = INT_MAX;            // running answer: smallest candidate seen so far

        while (low <= high)            // shrink window until it's empty (low crosses high)
        {
            int mid = low + (high - low) / 2;
            // midpoint of current window
            // (low + high)/2 could overflow for huge arrays, so we use this safer form

            if (nums[mid] >= nums[low])
            // CASE A: left half [low ... mid] is sorted (no break inside it)
            // Reason: in a normal sorted stretch, first element <= middle element
            {
                mini = min(mini, nums[low]);
                // nums[low] is the smallest value in this sorted left half
                // -> valid candidate for the overall minimum, so record it

                low = mid + 1;
                // left half fully accounted for -> discard it
                // move window to the right half: [mid+1 ... high]
            }

            else if (nums[mid] <= nums[high])
            // CASE B: right half [mid ... high] is sorted instead
            // (we only reach here if CASE A was false, meaning nums[mid] < nums[low],
            //  so the rotation "seam" is somewhere within the left half)
            {
                mini = min(mini, nums[mid]);
                // nums[mid] is the smallest value in this sorted right half
                // -> valid candidate for the overall minimum, so record it

                high = mid - 1;
                // right half fully accounted for -> discard it
                // move window to the left half: [low ... mid-1]
            }
        }

    return mini;   // smallest candidate collected across all shrinking windows = answer
    }
};