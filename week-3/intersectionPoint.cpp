/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int a=0, b=0;
        while(tempA!=NULL) {
            a++;
            tempA = tempA->next;
        }
        
        while(tempB!=NULL) {
            b++;
            tempB = tempB->next;
        }
        
        int d = abs(a-b);
        tempA = headA;
        tempB = headB;
        if(a>b) {
            while(d--) {
                tempA = tempA->next;
            } 
        } else {
            while(d--) {
                tempB = tempB->next;
            }
        }
        
        while(tempA!=NULL && tempB!=NULL) {
            if(tempA == tempB) {
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        
        return NULL;
    }
};