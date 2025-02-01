class Solution {
    void dfs(int r,int c,vector<vector<int>>& image, vector<vector<int>>& ans,int newcolor,int ini,int dr[],int dc[]){
        ans[r][c]=newcolor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=r+dr[i];
            int ncol=c+dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==ini && ans[nrow][ncol]!=newcolor){
                dfs(nrow,ncol,image,ans,newcolor,ini,dr,dc);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        int initialColor=image[sr][sc];
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        dfs(sr,sc,image,ans,color,initialColor,dr,dc);
        return ans;
    }
};