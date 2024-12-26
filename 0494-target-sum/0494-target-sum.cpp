class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return cal(nums, target, 0, 0);
    }
    int cal(vector<int>& nums, int tar, int i, int currSum) {
        if (i == nums.size()) {
            return (currSum == tar) ? 1 : 0;
        }

        int a= cal(nums, tar, i + 1, currSum + nums[i]);
        int b= cal(nums, tar, i+ 1, currSum - nums[i]);

        return a+b;
    }
};