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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int x= root->val, y = p->val, z = q->val;
        if(x == y || x == z) return root;
        if(x < max(y,z) && x > min(y,z)) return root;
        if(x < min(y,z)) return lowestCommonAncestor(root->right,p,q);
        return lowestCommonAncestor(root->left,p,q);
    }
};
