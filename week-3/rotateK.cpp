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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev_temp;
        int size = 0;
        while(temp!=NULL) {
            size++;
            temp=temp->next;
        }
        if(size>0)
        k = k%size;
        while(k-- && head!=NULL) {
            prev_temp = head;
            temp = head;
            while(temp->next != NULL) {
                prev_temp = temp;
                temp=temp->next;
            }
            temp->next = head;
            head = temp;
            prev_temp->next = NULL;
        } 
        return head;
    }
};