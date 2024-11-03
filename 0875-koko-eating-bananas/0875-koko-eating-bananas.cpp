int maxelement(vector<int> &v){
    int maxi=INT_MIN;
    int n=v.size();
    for(int i=0;i<n;i++){
        maxi=max(maxi,v[i]);
    }
    return maxi;
}

long long totalhours(vector<int> &v,int hourly){
    long long totalh=0;
    int n=v.size();
    for(int i=0;i<n;i++){
        totalh+=ceil((double)v[i]/hourly);
    }
    return totalh;
}



class Solution {
public:
    int minEatingSpeed(vector<int>& piles, long long  h) {
        int n=piles.size();
        int low=1;
        int ans=INT_MAX;
        int high=maxelement(piles);
        while(low<=high){
            int mid=(low+high)/2;
            long long  totalh=totalhours(piles,mid);
            if(totalh<=h){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};