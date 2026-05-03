class Solution {
public:
    char toComp(char a){
        if(a>='A'&& a<='Z'){
            cout<< a << " <-";
            return a+32;
        }
    }

    bool isAlphaN(char a){
        if(a>='a'&& a<='z') return true;
        if(a>='A'&& a<='Z') return true;
        if(a>='0'&& a<='9') return true;
        return false;
    }
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j=n-1;
        while(i<j){
            while(i<j && !isAlphaN(s[i])){
                    i++;
                }
            while(j>i && !isAlphaN(s[j])){
                j--;
            }
            char a = tolower(s[i]),b = tolower(s[j]);
            if(a-'a'!=b-'a'){
                cout << a <<"[[[]]]" << b << " " << i << " " << j;

                return false;
            }
            i++;j--;
        }
        return true;
    }
};
