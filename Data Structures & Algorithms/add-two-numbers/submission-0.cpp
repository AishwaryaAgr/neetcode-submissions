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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* i1 = l1, *i2=l2;
        ListNode *ans = new ListNode(0),*a=ans;
        int c=0;
        while(i1 && i2){
            int s = i1->val + i2->val+c;
            c = s/10;
            s%=10;
            ListNode* temp = new ListNode(s);
            a->next = temp;
            a=a->next;
            i1=i1->next;
            i2=i2->next;
        }
        while(i1){
            int s = i1->val+c;
            c = s/10;
            s%=10;
            ListNode* temp = new ListNode(s);
            a->next = temp;
            a=a->next;
            i1=i1->next;
        }
        while(i2){
            int s = i2->val+c;
            c = s/10;
            s%=10;
            ListNode* temp = new ListNode(s);
            a->next = temp;
            a=a->next;
            i2=i2->next;
        }
        if(c){
            ListNode* temp = new ListNode(c);
            a->next = temp;
            a=a->next;
        }
        return ans->next;
    }
};
