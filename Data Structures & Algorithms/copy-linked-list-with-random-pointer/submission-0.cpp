/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> rand;
    Node* allRandom(Node* head){
        if(!head) return head;
        rand[head] = head->random;
        Node* root = new Node(head->val);
        root->random = head->random;
        head->random = root;
        root->next = allRandom(head->next);
        return root;
    }
    Node* copyRandomList(Node* head) {
        rand.clear();
        Node* copied = allRandom(head);
        Node* itr = head;
        while(itr){
            if(!rand[itr]){
                itr->random->random = NULL;
            }else{
                itr->random->random = rand[itr]->random;
            }
            itr = itr->next;
        }
        itr = head;
        while(itr){
            itr->random = rand[itr];
            itr = itr->next;
        }
        return copied;
    }
};
