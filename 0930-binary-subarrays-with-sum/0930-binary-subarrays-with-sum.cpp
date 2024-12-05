class Solution {
public:
    int func(vector<int>&nums, int goal){
        if(goal<0) return 0;
        int n=nums.size();
        int l=0,r=0,sum=0,count=0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l=l+1;
            }
            count=count+(r-l+1);
            r=r+1;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums,goal)-func(nums,goal-1);
    }
};