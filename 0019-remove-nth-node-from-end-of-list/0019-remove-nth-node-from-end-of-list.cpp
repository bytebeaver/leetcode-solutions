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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head == NULL || head->next == NULL)
        return NULL;

        int length=0;

        ListNode *temp = head;

        while(temp != NULL)
        {
            length++;
            temp=temp->next;
        }
        
        //nth node from back is length-n+1 th node from front
        int k = length-n+1;

        if(k==1)
        {
            ListNode *newhead = head->next;
            head->next= NULL;
            return newhead;
        }
        int i=1;

        ListNode *prev=head;
        ListNode *current=head->next;

        while(current != NULL)
        {
            if(i==k-1)
            {
                //remove the node
                prev->next = current->next;
                delete current;
                break;
            }

            i++;
            prev=prev->next;
            current=current->next;
        }
        
    return head;
    }
};