class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        // ============================================================
        // DATA STRUCTURES
        // ============================================================

        // left_max_heap = MAX-heap
        // Window ke CHHOTE (smaller) half ke elements yahan rehte hain.
        // Top hamesha is heap ka SABSE BADA element hoga -- jo actually
        // poore window ka "middle-left" element hai (candidate for median).
        priority_queue<pair<int, int>> left_max_heap;

        // right_min_heap = MIN-heap
        // Window ke BADE (bigger) half ke elements yahan rehte hain.
        // Top hamesha is heap ka SABSE CHHOTA element hoga -- jo actually
        // poore window ka "middle-right" element hai (candidate for median).
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> right_min_heap;

        int n = nums.size();

        // flag[i] = true  -> nums[i] abhi left_max_heap mein hai
        // flag[i] = false -> nums[i] abhi right_min_heap mein hai
        // Ye array humein batata hai ki jab koi index window se bahar
        // jaaye, toh use kis heap se (logically) hataana hai.
        vector<bool> flag(n, false);

        vector<double> result;

        // stale_nodes_in_left_max_heap / stale_nodes_in_right_min_heap:
        // Kitne "purane" (window se bahar ja chuke) elements ABHI BHI
        // physically heap ke andar pade hain, lekin unhe size count
        // karte waqt IGNORE karna hai (kyunki heap se seedha O(1) mein
        // arbitrary index delete nahi ho sakta -- sirf top hi accessible
        // hota hai). Ye "lazy deletion" ka core idea hai.
        //
        // Effective (real, usable) size formula:
        //   real size of left_max_heap  = left_max_heap.size()  - stale_nodes_in_left_max_heap
        //   real size of right_min_heap = right_min_heap.size() - stale_nodes_in_right_min_heap
        int stale_nodes_in_left_max_heap = 0;
        int stale_nodes_in_right_min_heap = 0;

        // ============================================================
        // MAIN LOOP -- ek ek karke har number ko process karo
        // ============================================================
        for (int i = 0; i < n; i++) {

            // --------------------------------------------------------
            // STEP 1: naya element (nums[i]) ko sahi heap mein daalo
            // --------------------------------------------------------
            // Rule: agar left_max_heap khaali hai, YA left_max_heap ka
            // top (sabse bada element) naye element se bada-ya-barabar
            // hai, toh naya element left_max_heap mein jaayega.
            // Warna ye right_min_heap mein jaayega.
            if (left_max_heap.empty() || left_max_heap.top().first >= nums[i]) {
                left_max_heap.push({nums[i], i});
                flag[i] = true;
            }
            else {
                right_min_heap.push({nums[i], i});
                flag[i] = false;
            }

            // --------------------------------------------------------
            // STEP 2: purana element mark karo (jo window se bahar gaya)
            // --------------------------------------------------------
            // Jab hum kam se kam k elements dekh chuke hain (i >= k),
            // toh exactly (i - k) index wala element ab window ke
            // BAHAR ja chuka hai (window ab [i-k+1 ... i] hai).
            //
            // Us element ko heap se turant nahi nikaal sakte (kyunki
            // heap sirf value-based organized hai, index/age-based
            // nahi -- arbitrary element dhoondhna O(n) hoga).
            //
            // Isliye sirf ek COUNTER badhate hain ("ek stale element
            // padha hai heap mein") -- actual physical removal tab
            // hoga jab wo element khud heap ke TOP par aayega.
            if (i >= k) {

                // index_going_out of the window is = i-k;

                if (flag[i-k] == true)
                    stale_nodes_in_left_max_heap++;   // outgoing element left mein tha
                else if (flag[i-k] == false)
                    stale_nodes_in_right_min_heap++;  // outgoing element right mein tha

                // Agar koi stale element PEHLE SE HI top par baitha hai
                // (kisi pichle iteration se), toh usko turant physically
                // pop kar do aur uska counter wapas kam kar do.
                while (!left_max_heap.empty() && left_max_heap.top().second <= i-k) //i-k is the index just before the window start
                {
                    left_max_heap.pop();
                    stale_nodes_in_left_max_heap--;
                }

                while (!right_min_heap.empty() && right_min_heap.top().second <= i-k)
                {
                    right_min_heap.pop();
                    stale_nodes_in_right_min_heap--;
                }
            }

            // --------------------------------------------------------
            // STEP 3a: REBALANCE -- agar right_min_heap zyada bada ho gaya
            // --------------------------------------------------------
            // Target invariant: (real size of left_max_heap) hamesha
            // (real size of right_min_heap) ke barabar ya usse EXACTLY
            // 1 zyada honi chahiye (taaki odd-k case mein median seedha
            // left_max_heap ke top se mil jaaye).
            //
            // Ye check karta hai: agar left kam hai (ya right zyada hai)
            // is tarah ki condition banti hai, toh right ka top nikaal
            // ke left mein bhej do.
            //rebalance ...to har element ke add hone pr krana hoga
            while (left_max_heap.size() - stale_nodes_in_left_max_heap > right_min_heap.size() + 1 - stale_nodes_in_right_min_heap) //left se right me transfer krna hoga..but usse pehle get rid of any stale nodes on top of left
            {
                if (!left_max_heap.empty() && left_max_heap.top().second <= i - k)
                {
                    // left ka apna top stale nikla -- sirf discard karo
                    left_max_heap.pop();
                    stale_nodes_in_left_max_heap--;
                }
                else
                {
                    // valid element -- right_min_heap mein shift karo
                    right_min_heap.push(left_max_heap.top());
                    flag[left_max_heap.top().second] = false;
                    left_max_heap.pop();
                }
            }

            // --------------------------------------------------------
            // STEP 3b: REBALANCE -- agar left_max_heap zyada bada ho gaya
            // --------------------------------------------------------
            // Agar left, right se bhi CHHOTA ho gaya (matlab right zyada
            // bada hai ya balance bigad gaya doosri taraf), toh right ka
            // top nikaal ke left mein bhej do.
            while (left_max_heap.size() - stale_nodes_in_left_max_heap < right_min_heap.size() - stale_nodes_in_right_min_heap)
            {
                if (!right_min_heap.empty() && right_min_heap.top().second <= i-k)
                {
                    // right ka apna top stale nikla -- sirf discard karo
                    right_min_heap.pop();
                    stale_nodes_in_right_min_heap--;
                }
                else
                {
                    // valid element -- left_max_heap mein shift karo
                    left_max_heap.push(right_min_heap.top());
                    flag[right_min_heap.top().second] = true;
                    right_min_heap.pop();
                }
            }

            // --------------------------------------------------------
            // STEP 4: FINAL SAFETY CLEANUP
            // --------------------------------------------------------
            // Rebalance (Step 3a/3b) ke baad bhi ho sakta hai ki DOOSRE
            // heap ka apna purana top stale reh gaya ho -- kyunki Step 3a
            // sirf right_min_heap ka top touch karta hai, Step 3b sirf
            // left_max_heap ka top touch karta hai. Ek doosre ke tops ko
            // kabhi cross-check nahi karte apne apne loop ke andar.
            //
            // Isliye ab dono heaps ke top ko ek final baar check karo.
            //after rebalancing there still can be stale nodes present on heaps lets get rid of them:
            while (!left_max_heap.empty() && left_max_heap.top().second <= i-k)
            {
                left_max_heap.pop();
                stale_nodes_in_left_max_heap--;
            }

            while (!right_min_heap.empty() && right_min_heap.top().second <= i-k)
            {
                right_min_heap.pop();
                stale_nodes_in_right_min_heap--;
            }

            //now time to get the median of the window
            // --------------------------------------------------------
            // STEP 5: MEDIAN nikaalo (agar window poori size ki ban chuki hai)
            // --------------------------------------------------------
            if (i >= k-1) //we have hit the window ...pehli baar k-1 pr hit hogi ..ex k=3 0 1 2 ..uske baad to hoti hi rahegi....ek ayega ek jayega
            {
                if (k % 2 == 1)
                {
                    // ODD window size -> left_max_heap (max-heap) ka
                    // top hi seedha median hai, kyunki invariant ke
                    // hisaab se left mein exactly 1 element extra hai.
                    double median = left_max_heap.top().first;
                    result.push_back(median);
                }
                else
                {
                    // EVEN window size -> dono heaps ke tops barabar
                    // count represent karte hain, isliye unka average
                    // hi median hoga. (double) cast dono operands pe
                    // laga hai taaki integer division na ho.
                    double median = ((double)left_max_heap.top().first + (double)right_min_heap.top().first) / 2.0;
                    result.push_back(median);
                }
            }

        }

        return result;
    }
};