class Solution {
public:
    string largestOddNumber(string s) {
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            if((s[i]-'0')%2!=0){
                return s.substr(0,i+1);
            }
        }
        return "";
    }
};