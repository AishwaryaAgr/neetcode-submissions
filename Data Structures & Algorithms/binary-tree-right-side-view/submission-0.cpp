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
    vector<int> ans;
    void solve(TreeNode* root, int pos){
        if(!root) return;
        
        if(ans.size() < pos){
            ans.push_back(0);
        }
        ans[pos-1] = root->val;
        solve(root->left,pos+1);
        solve(root->right,pos+1);
        

    }

    vector<int> rightSideView(TreeNode* root) {
        ans = {};
        solve(root,1);
        return ans;
    }
};
