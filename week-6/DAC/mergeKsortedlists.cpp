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
    
    ListNode* combine(ListNode* h1, ListNode* h2) {
        ListNode *head = NULL;
        if(!h1 && !h2) {
            return head;
        }
        if(!h1) {
            head = h2;
            return head;
        }
        
        if(!h2) {
            head = h1;
            return head;
        }
        if(h1->val < h2->val) {
            head = h1;
            h1 = h1->next;
        } else {
            head = h2;
            h2 = h2->next;
        }
        ListNode *curr = head;
        while(h1 && h2) {
            if(h1->val < h2->val) {
                curr->next = h1;
                curr = curr->next;
                h1 = h1->next;
            } else {
                curr->next = h2;
                curr = curr->next;
                h2 = h2->next;
            }
        }
        
        while(h1) {
            curr->next = h1;
            curr = curr->next;
            h1 = h1->next;
        }
        
        while(h2) {
            curr->next = h2;
            curr = curr->next;
            h2 = h2->next;
        }
        return head;
    }
    
    ListNode* merge(vector<ListNode*> &lists, int left, int right) {
        if(left == right) {
            return lists[left];
        }
        int size = right - left + 1;
        ListNode *h1, *h2, *head;
        h1 = h2 = head = NULL;
        h1 = merge(lists, left, left + size/2 - 1);
        h2 = merge(lists, left + size/2, right);
        head = combine(h1, h2);
        return head;
    }
    
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0)
            return NULL;
        return merge(lists, 0, lists.size()-1);
    }
};