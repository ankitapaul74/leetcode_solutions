class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n=s.length();
        int r=0,l=0;
        int hash[256];
        int length=0;
        memset(hash, -1, sizeof(hash)); 
        int maxlen=0;
        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            length=r-l+1;
            maxlen=max(length,maxlen);
            hash[s[r]]=r;
            r++;
        }
        
           return maxlen;
    }
};