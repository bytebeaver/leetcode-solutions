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
 

 //BRUTE FORCE:
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
        
//         ListNode *temp = head;
//         int count=0;

//         while(temp != NULL)
//         {
//             count++;
//             temp=temp->next;
//         }

//         int middleNode = count/2 + 1;

//         temp = head;

//         while(temp != NULL)
//         {
//             middleNode = middleNode-1;

//             if(middleNode == 0)
//             break;

//             temp = temp->next;
//         }
//         return temp;
//     }
// };

//OPTIMIZED : USING TORTOISE HARE ALGORITHM (STRIVER)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL /*in case n is even*/  && fast->next != NULL /*n is odd*/) //n = number of nodes in linked list
        {
            slow = slow->next;
            fast = fast->next->next;

        }

        return slow;
    }
};