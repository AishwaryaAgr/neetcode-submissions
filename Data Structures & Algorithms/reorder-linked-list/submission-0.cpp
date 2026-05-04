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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        ListNode* itr=head;
        while(itr->next->next) itr=itr->next;
        ListNode* temp = head->next;
        head->next = itr->next;
        itr->next = NULL;
        head->next->next = temp;
        reorderList(temp);
        return;
    }
};
