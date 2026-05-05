class Solution {
public:
    bool canEat(vector<int>& piles, int h,int speed){
        int ans = 0;
        for(int pile:piles){
            ans+= pile/speed;
            if(pile%speed) ans++;
        }
        return (ans<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n =piles.size();
        int start=1,end= piles[n-1];
        if(n==1){
            return piles[0]%h ? (piles[0]/h)+1 : piles[0]/h;
        }
        while(start<=end){
            int mid = (start+end)/2;
            cout << mid << " ";
            int first = canEat(piles,h,mid), second= canEat(piles,h,mid-1);
            if(first == true && second==false) return mid;
            if(second == false){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return 0;
    }
};
