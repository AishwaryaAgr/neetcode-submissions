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
    int sumIncRoot(TreeNode* root){
        if(!root) return 0;
        int l = sumIncRoot(root->left);
        int r = sumIncRoot(root->right);
        l=max(l,0);
        r=max(r,0);
        int x = root->val;
        int y = max(l,r);
        x+=y;
        ans = max(ans,x);
        ans = max(ans, root->val+r+l);
        return x;
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        ans = root->val;
        int l = sumIncRoot(root);
        return ans;
    }
};
