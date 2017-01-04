//https://leetcode.com/problems/merge-k-sorted-lists/

#define  PII pair<int, int>
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<PII, vector< PII >, greater< PII > > q;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] == NULL)
                continue;
            q.push(PII(lists[i]->val, i));
            lists[i] = lists[i] -> next;
        }
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        while(!q.empty()) {
            PII t = q.top();
            q.pop();
            if(lists[t.second] != NULL) {
                q.push(PII(lists[t.second]->val, t.second));
                lists[t.second] = lists[t.second] -> next;
            }
            tail->next = new ListNode(t.first);
            tail = tail -> next;
        }
        return head->next;
    }
};
