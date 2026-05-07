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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N,";
        string ans = to_string(root->val);
        ans+=",";
        ans+= serialize(root->left);
        ans+=serialize(root->right);
        cout << ans << " ";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* ans = new TreeNode(-1);
        stack<pair<TreeNode*,int> > latest;
        if(data[0] == 'N') return NULL;
        int start =0,curr=0;
        while(data[start] != ','){
            curr*=10;
            curr+= data[start++]-'0';
            ans->val = curr;
            curr=0;
        }
        start++;
        latest.push(make_pair(ans,1));
        latest.push(make_pair(ans,0));
        while(start<data.size() && latest.size()){
            if(data[start] == ','){
                TreeNode* c = latest.top().first;
                int pos = latest.top().second;
                latest.pop();
                TreeNode* add = new TreeNode(curr);
                if(pos){
                    c->right = add;
                }else{
                    c->left = add;
                }
                latest.push(make_pair(add,1));
                latest.push(make_pair(add,0));
                curr = 0;
                start++;

            }else if(data[start] == 'N'){
                start+=2;
                curr = 0;
                latest.pop();
            }
            else{
                curr*=10;
                curr+= data[start++]-'0';
            }
        }
        return ans;
    }
};
