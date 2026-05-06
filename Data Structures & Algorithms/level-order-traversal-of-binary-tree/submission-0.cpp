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
    unordered_map<int,vector<int> > mp;   
    void solve(TreeNode* root,int pos){
        if(!root) return;
        if(mp.find(pos) == mp.end()){
            mp[pos] = {};
        }
        mp[pos].push_back(root->val);
        solve(root->left,pos+1);
        solve(root->right,pos+1);
        return;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        unordered_map<int,vector<int> > temp;
        mp=temp;
        solve(root,0);
        vector<vector<int> > ans(mp.size());
        for(auto it: mp){
            ans[it.first]=it.second;
        }
        return ans;
    }
};
