class Solution {
public:
    struct comp {
        bool operator()(pair<ListNode*, int> a, pair<ListNode*, int> b) {
            return a.first->val > b.first->val;
        }
    };
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0)
            return NULL;
        ListNode *head, *tail;
        head=tail=NULL;
        priority_queue<pair<ListNode*, int>, vector<pair<ListNode*, int>>, comp> pq;
        vector<ListNode*> curr(k);
        
        for(int i=0; i<k; i++) {
            curr[i] = lists[i];
            if(curr[i] != NULL) {
                pq.push({curr[i], i});
            }
        }
        if(pq.empty()) {
            return NULL;
        }
        
        head = tail = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        curr[idx] = curr[idx]->next;
        if(curr[idx] != NULL) {
            pq.push({curr[idx], idx});
        }
        
        while(!pq.empty()) {
            ListNode* temp = pq.top().first;
            idx = pq.top().second;
            pq.pop();
            tail->next = temp;
            tail = tail->next;
            curr[idx] = curr[idx]->next;
            if(curr[idx] != NULL) {
                pq.push({curr[idx], idx});
            }
        }
        return head;
    }
};