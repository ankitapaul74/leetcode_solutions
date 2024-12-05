class Solution {
public:
    int func(vector<int>& nums,int k){
        int n=nums.size();
        int l=0,r=0,count=0;
        map<int,int>mpp;
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                    
                }
                l=l+1;
            }
            count=count+(r-l+1);
            r=r+1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
};