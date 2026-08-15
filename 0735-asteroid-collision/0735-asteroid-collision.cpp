class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      
      stack<int> st;  // stack maintains surviving asteroids in left-to-right order (bottom=leftmost, top=most recent)
     
       for( int &a : asteroids)   // reference loop: 'a' will be mutated to 0 if it explodes
       {
            // collision only possible when: current is left-moving AND
            // last surviving (top) asteroid is right-moving -> they're heading toward each other
            while(!st.empty() && a< 0 && st.top()> 0)
            {
                int sum = a + st.top();   // trick to compare magnitudes since signs are opposite

                if(sum<0)
                st.pop();   
                // top's magnitude was smaller -> top explodes, 'a' survives,
                // loop continues to check against the NEW top (chain reaction handling)

                else if(sum > 0)
                {
                    a=0;    // 'a' was smaller -> 'a' explodes; use 0 as a "destroyed" marker  //beacause no value can be 0 in asteroid array so this will break out of while
                    // while condition (a<0) becomes false next check -> loop exits naturally
                }

                else if(sum ==0)
                {
                    st.pop();   // equal size -> both explode
                    a=0;
                }
            }

            if(a!=0)          // only push if 'a' survived all its collisions
            st.push(a);
       }

       int s = st.size();

       vector<int> result(s);   // pre-sized, zero-initialized vector — safe since we index-assign, not push_back

       int i = s-1;             // fill from the back since stack.top() = rightmost surviving asteroid

       while(i >=0)
       {
        result[i] = st.top();   // index-assign (correct, unlike push_back which would double the size)
        st.pop();
        i--;
       }

       return result;

    
}
     

};