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
    ListNode* swapPairs(ListNode* head) {
        
        int count = 0;
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        while(curr != NULL && count<2) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(next != NULL) {
            head->next = swapPairs(next);
        }
        return prev;
    }
};