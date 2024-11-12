class Solution {
public:
    int binaryans(vector<vector<int>>& items,int qp){
        int l=0;
        int r=items.size()-1;
        int mid;
        int maxBeauty=0;
        while(l<=r){
            mid= l+ (r-l)/2;
            if(items[mid][0]>qp){
                r=mid-1;
            }else{
                maxBeauty=max(maxBeauty,items[mid][1]);
                l=mid+1;
            }
        }
        return maxBeauty;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=items.size();
        int m=queries.size();
        vector<int> results(m);
        sort(begin(items),end(items));
        int maxi=items[0][1];
        for(int i=1;i<n;i++){
            maxi=max(maxi,items[i][1]);
            items[i][1]=maxi;
        }
        for(int i=0;i<m;i++){
            int qp=queries[i];
            results[i]=binaryans(items,qp);
        }
        return results;
    }
};