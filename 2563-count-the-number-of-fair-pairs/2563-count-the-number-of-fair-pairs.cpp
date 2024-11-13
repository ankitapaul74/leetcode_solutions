class Solution {
public:
    long long lowerbound(vector<int> &nums,int low,int high,int element){
        while(low<=high){
            int mid=low+ (high-low)/2;
            if(nums[mid]>=element){
                high=mid-1; 
            }else{
                low=mid+1;
            }
        }
        return low;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long result=0;
        for(int i=0;i<nums.size();i++){
            int low=lowerbound(nums,i+1,nums.size()-1,lower-nums[i]);
            int high=lowerbound(nums,i+1,nums.size()-1,upper-nums[i]+1);
            
            result+=1*(high-low);
        }
        return result;
       
    }
};