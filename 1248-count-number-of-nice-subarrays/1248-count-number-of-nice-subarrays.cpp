class Solution {
public:
    int func(vector<int>&nums,int k){
        int n=nums.size();
        if(k<0) return 0;
        int l=0,r=0,sum=0,count=0;
        while(r<n){
            sum+=nums[r]%2;
            while(sum>k){
                sum=sum-nums[l]%2;
                l=l+1;
            }
            count=count+(r-l+1);
            r=r+1;
        }
        return count;
        
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
        
    }
};