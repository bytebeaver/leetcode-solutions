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

 //ITERATIVE : 

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode *temp = head;
//         ListNode *back = NULL;

//         ListNode *front;

//         while(temp != NULL)
//         {
//             front = temp->next;
//             temp->next = back;
//             back = temp;
//             temp = front;
//         }

//     return back;
//     }
// };


//RECURSIVE:
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
        return head;

        ListNode *NewHead = reverseList(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next=NULL;

        return NewHead;
    }
};

