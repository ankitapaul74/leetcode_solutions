class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int len=0,maxlen=0;
        int l=0,r=0;
        int count=0;
        while(r<n){
            if(nums[r]==0){
                count++;
            }
            if(count>k){
                if(nums[l]==0)
                     count--;
                l++;
            } len=r-l+1;
                maxlen=max(len,maxlen);
            r++;
        }
        return maxlen;
    }
};