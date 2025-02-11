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

//STRIVER


 //BRUTE FORCE ----> MY OWN SOLUTION 
                //strivers brute force is similar ....check in notes
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
        
//         if(head == NULL || head->next == NULL)
//         return NULL;

//         int length=0;

//         ListNode *temp = head;

//         while(temp != NULL)
//         {
//             length++;
//             temp=temp->next;
//         }
        
//         //nth node from back is length-n+1 th node from front
//         int k = length-n+1;

//         if(k==1)
//         {
//             ListNode *newhead = head->next;
//             head->next= NULL;
//             return newhead;
//         }
//         int i=1;

//         ListNode *prev=head;
//         ListNode *current=head->next;

//         while(current != NULL)
//         {
//             if(i==k-1)
//             {
//                 //remove the node
//                 prev->next = current->next;
//                 delete current;
//                 break;
//             }

//             i++;
//             prev=prev->next;
//             current=current->next;
//         }
        
//     return head;
//     }
// };



class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //we will use fast and slow pointer but NOT like tortoise hare algorithm

        ListNode *slow = head;
        ListNode *fast = head;

        //we are moving the fast n steps ahead
        for(int i=1; i<=n ; i++)
        {
            fast=fast->next;
        }

        if(fast == NULL)//it means we have to delete the first node
        {
            ListNode *newhead = head->next;
            delete head;
            return newhead;
        }

        //now we will move fast and slow one at a time till "fast" reaches the last node 
        //by doing this "slow" will reach the node previous to the node to be deleted
        while(fast->next != NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }

        ListNode *tobeDeleted = slow->next;
        slow->next=slow->next->next; //slow = tobeDeleted->next
        delete tobeDeleted;

        return head;
    }
};