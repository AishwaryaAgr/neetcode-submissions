class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(string token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int s= nums.top();
                nums.pop();
                int f = nums.top();
                nums.pop();
                if(token == "+"){
                   f+=s; 
                }
                if(token == "-"){
                   f-=s; 
                }
                if(token == "*"){
                   f*=s; 
                }
                if(token == "/"){
                   f/=s; 
                }
                nums.push(f);
            }else{
                nums.push(stoi(token));
            }
        }
        return nums.top();
    }
};
