/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        
        ListNode *temp  = head;

        //getting the size of the list
        int size =0;


        while(temp != NULL)
        {
            size++;
            temp=temp->next;
        }

        vector<int> values(size);

        temp = head;

        int i=0;
        while(temp != NULL && i<size)
        {
            values[i] = temp->val;
            temp = temp->next;
            i++;
        }
        stack<int> st;
        vector<int> nge(size);

        for(int i=size-1; i>=0; i--)
        {
            
            while(!st.empty() && st.top()<= values[i])
            st.pop();

            if(st.empty())
            nge[i] = 0;

            else
            nge[i] = st.top();

            st.push(values[i]);
        }

        return nge;
    }
};