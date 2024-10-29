class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       long long n=nums.size();
        long long low=0,high=n-1;
        int ans=n;
        while(low<=high){
            long long mid=(low+high)/2;
            if(nums[mid]>=target){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};