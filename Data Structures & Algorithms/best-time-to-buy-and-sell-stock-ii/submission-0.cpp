class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pro = 0;
        int curr = prices[0];
        int n = prices.size(),i=1;

        while(i<n){
            if(prices[i] > curr){
                pro += prices[i]-curr;
                curr = prices[i];
            }else{
                curr = prices[i];
            }
            i++;
        }
        return pro;
    }
};