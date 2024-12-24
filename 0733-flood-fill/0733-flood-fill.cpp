class Solution {
    void dfs(int row,int col,vector<vector<int>>&ans,vector<vector<int>>&image,int                    ini,int newColor,int delr[],int delc[]){
        ans[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nr=row+delr[i];
            int nc=col+delc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && ans[nr][nc]!=newColor && 
               image[nr][nc]==ini){
                dfs(nr,nc,ans,image,ini,newColor,delr,delc);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int initialColor=image[sr][sc];
        vector<vector<int>> ans=image;
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        dfs(sr,sc,ans,image,initialColor,color,delr,delc);
        return ans;
        
    }
    
};