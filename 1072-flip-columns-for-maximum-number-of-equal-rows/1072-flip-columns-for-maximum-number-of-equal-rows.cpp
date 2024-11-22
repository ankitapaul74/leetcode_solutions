class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n=matrix.size();
        unordered_map<string,int>freq;
        for(auto & cR:matrix){
            string pattern=" ";
            for(int col=0;col<cR.size();col++){
                if(cR[0]==cR[col]){
                    pattern+="T";
                }else{
                    pattern+="F";
                }
            }
            freq[pattern]++;
        }
        int maxi=0;
        for(auto & it:freq){
            maxi=max(maxi,it.second);
        }
        return maxi;
    }
};