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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode* itr = head;
        while(itr){
            itr=itr->next;
            sz++;
        }
        int hops = sz-n-1;
        if(hops == -1) return head->next;
        itr = head;
        while(hops--){
            itr=itr->next;
        }
        itr->next = itr->next->next;
        return head;
    }
};
