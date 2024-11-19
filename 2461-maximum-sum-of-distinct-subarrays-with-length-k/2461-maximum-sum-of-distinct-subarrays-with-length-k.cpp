class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long n=nums.size();
        long long max_sum=0;
        long long sum=0;
        int left=0,right=0;
        unordered_set<int> s;
       while(right<n){
           while(s.count(nums[right])){
            sum-=nums[left];
            s.erase(nums[left]);
            left++;
           }
          sum+=nums[right];
          s.insert(nums[right]);
          if(right-left+1 ==k){
            max_sum=max(max_sum,sum);
            sum-=nums[left];
            s.erase(nums[left]);
            left++;
          }
          right++;
       }
       return max_sum;
    }
};