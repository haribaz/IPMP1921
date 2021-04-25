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
       
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        int size = 0; 
        while(temp!=NULL) {
            size++;
            temp=temp->next;
        }
        cout<<size<<endl;
        ListNode* current=head;
        ListNode* prev=NULL;
        ListNode* aduthu=NULL;
        int count = 0;
        while(current != NULL && count < k) {
        aduthu = current->next;
        current->next = prev;
        prev = current;
        current = aduthu;
        count++;
    }
    size = size - k;

    if(aduthu != NULL && k<=size) {
        head->next = reverseKGroup(aduthu, k);
    } else {
        head->next = aduthu;
    }
        return prev;
        
}
};