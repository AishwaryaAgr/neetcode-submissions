class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size(), m=s2.size();
        vector<int> ref(26,0), temp = ref;
        for(char a:s1){
            ref[a-'a']++;
        }
        for(int i=0;i<n;i++){
            ref[s2[i]-'a']--;
        }
        if(ref == temp) return true;
        for(int j=n;j<m;j++){
            cout<< s2[j] << " ";
            ref[s2[j]-'a']--;
            ref[s2[j-n]-'a']++;

            if(ref == temp) return true;
        }
        return false;
    }
};
