
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
        
        ListNode *temp = head;

        // Step 1: Find the number of nodes in the linked list
        int size = 0;

        while(temp != NULL)
        {
            size++;
            temp = temp->next;
        }

        // Step 2: Store all linked list values in an array
        // This allows us to access elements from right to left
        vector<int> values(size);

        temp = head;

        int i = 0;

        while(temp != NULL && i < size)
        {
            values[i] = temp->val;
            temp = temp->next;
            i++;
        }

        // Stack will store possible next greater elements
        // We process the array from right to left
        stack<int> st;

        // nge[i] will contain the next greater element for values[i]
        vector<int> nge(size);

        // Step 3: Find Next Greater Element for every element
        // Start from the last element and move towards the first
        for(int i = size - 1; i >= 0; i--)
        {
            // Remove all elements that are smaller than or equal to
            // the current element because they cannot be its next greater element
            while(!st.empty() && st.top() <= values[i])
                st.pop();

            // If stack is empty, there is no greater element to the right
            if(st.empty())
                nge[i] = 0;

            // Otherwise, the top of the stack is the nearest greater element
            else
                nge[i] = st.top();

            // Add the current element to the stack
            // It may be the next greater element for some element on its left
            st.push(values[i]);
        }

        // Return the next greater element for every node
        return nge;
    }
};

