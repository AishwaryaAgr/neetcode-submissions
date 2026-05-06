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
    int ans;
    void solve(TreeNode* root,int mxyet){
        if(!root) return;
        if(root->val >= mxyet) ans++;
        mxyet = max(mxyet,root->val);
        solve(root->left,mxyet);
        solve(root->right,mxyet);
    }
    int goodNodes(TreeNode* root) {
        ans = 0;
        if(!root) return 0;
        ans++;
        solve(root->left,root->val);
        solve(root->right,root->val);
        return ans;
    }
};
