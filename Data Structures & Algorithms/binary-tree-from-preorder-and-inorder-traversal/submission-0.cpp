/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(vector<int>& pre, int ps, int pe, vector<int>& in,int is, int ie){
        if(pe<ps) return NULL;
        int fin = is,mov=0;
        while(in[fin] != pre[ps]){
            fin++;
            mov++;
        }
        TreeNode* head = new TreeNode(in[fin]);
        head->left = solve(pre,ps+1,ps+mov,in,is,fin-1);
        head->right = solve(pre,ps+mov+1,pe,in,fin+1,ie);
        return head;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        if(n==0) return NULL;

        return solve(pre,0,n-1,in,0,n-1);

    }
};
