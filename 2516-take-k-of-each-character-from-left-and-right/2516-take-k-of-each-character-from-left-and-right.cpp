class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.size();
        int cnta=0;
        int cntb=0;
        int cntc=0;
        int ans=0;
        for(char &ch:s){
            if(ch=='a'){
                cnta++;
            }else if(ch=='b'){
                cntb++;
            }else if(ch=='c'){
                cntc++;
            }
        }
        if(cnta<k ||cntb<k || cntc<k){
            return -1;
        }
         int i=0,j=0;
        while(j<n){
            if(s[j]=='a'){
                cnta--;
            }else  if(s[j]=='b'){
                cntb--;
            } if(s[j]=='c'){
                cntc--;
            }
            while(i<=j &&(cnta<k || cntb<k || cntc<k)){
               if(s[i]=='a'){
                cnta++;
            }else if(s[i]=='b'){
                cntb++;
            }else if(s[i]=='c'){
                cntc++;
            }
            i++;
            }

       ans=max(ans,j-i+1);
       j++;
        }
        return n-ans;

    }
};