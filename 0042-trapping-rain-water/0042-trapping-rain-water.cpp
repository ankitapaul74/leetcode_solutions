class Solution {
public:
    int trap(vector<int>& arr) {
       
        int lmax=0,rmax=0,l=0,r=arr.size()-1;
        int total=0;
        while(l<r){
            if(arr[l]<=arr[r]){
                if(lmax>arr[l]){
                    total+=lmax-arr[l];
                }else{
                    lmax=arr[l];
                }
                l=l+1;
            }else{
                if(rmax>arr[r]){
                    total+=rmax-arr[r];
                }else{
                    rmax=arr[r];
                }
                r=r-1;
            }
        }
        return total;
    }
};