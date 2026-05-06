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
    int pos(TreeNode* root){
        if(!root) return 0;
        int l = pos(root->left);
        int r = pos(root->right);
        return 1+l+r;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root) cout<< root->val << " ";
        int p = 1+pos(root->left);
        if(p == k) return root->val;
        if(p < k){
            return kthSmallest(root->right, k-p);
        }
        return kthSmallest(root->left,k);
    }
};
