class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        for(char a:s){
            if(a == ')'){
                if(!q.size() || q.top() != '('){
                    return false;
                }
                else{
                    q.pop();
                }
            }
            else if(a == ']'){
                if(!q.size() || q.top() != '['){
                    return false;
                }
                else{
                    q.pop();
                }
            }
            else if(a == '}'){
                if(!q.size() || q.top() != '{'){
                    return false;
                }
                else{
                    q.pop();
                }
            }
            else{
                q.push(a);
            }
        }
        if(q.size()) return false;
        return true;
    }
};
