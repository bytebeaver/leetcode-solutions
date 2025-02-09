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

    ListNode *reverseLL(ListNode *head)
    {
        if(head == NULL || head->next == NULL)
        return head;

        ListNode *newhead = reverseLL(head->next);

        ListNode *front = head->next;
        front->next=head;
        head->next= NULL;
        return newhead;

    }

    bool isPalindrome(ListNode* head)
    {
        //edge case with 0 or 1 node 
        if(head == NULL || head->next == NULL)return true;


        //tortoise hare to find middle
        ListNode *slow=head;
        ListNode *fast=head;

        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        //reverse the second half 
        ListNode *newhead=reverseLL(slow->next);


        //compare the 2 sublists
        ListNode* first =head;
        ListNode *second = newhead;

        while(second != NULL)
        {
            if(first->val != second->val)
            {
                reverseLL(newhead);//redoing the changes to original input ...this had nothing to do with logic
                return false;
            }
            first=first->next;
            second=second->next;
        }

    reverseLL(slow->next);//redoing the changes to original input ...this had nothing to do with logic
    return true;

    }
};