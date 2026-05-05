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
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* itr = head;
        while(itr->next->next) itr = itr->next;
        ListNode* ans = itr->next;
        itr->next = NULL;
        ans->next = reverse(head);
        return ans;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode* itr = head;
        for(int i=1;i<k;i++){
            if(itr->next) itr = itr->next;
            else return head;
        }
        ListNode* follow = reverseKGroup(itr->next,k);
        itr->next = NULL;
        ListNode* rev = reverse(head);
        ListNode* temp = rev;
        while(temp->next) temp = temp->next;
        temp->next = follow;
        return rev;
    }
};
