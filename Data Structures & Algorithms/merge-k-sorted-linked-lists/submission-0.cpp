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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode(0),*itr = ans;
        int n = lists.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            if(lists[i]){
                pq.push(make_pair(0-lists[i]->val,i));
                lists[i] = lists[i]->next;
            }
        }
        while(pq.size()){
            int val = pq.top().first;
            int ind = pq.top().second;
            pq.pop();
            ListNode* nxt = new ListNode(0-val);
            if(lists[ind]){
                pq.push(make_pair(0-lists[ind]->val,ind));
                lists[ind] = lists[ind]->next;
            }
            itr->next = nxt;
            itr = itr->next;
        }
        return ans->next;;
    }
};
