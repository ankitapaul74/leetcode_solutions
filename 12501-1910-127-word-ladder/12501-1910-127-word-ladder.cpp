class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int ans=q.front().second;
            q.pop();
            if(word==endWord) return ans;
            for(int i=0;i<word.size();i++){
                int ori=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,ans+1});
                        st.erase(word);
                    }
                }
                word[i]=ori;
            }
        }
        return 0;
    }
};