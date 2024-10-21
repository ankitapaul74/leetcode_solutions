class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int positiveindex=0;int negativeindex=1;
        int n=nums.size();
        vector<int> rearranged(n);
        for(int i=0;i<n;i++ ){
            if(nums[i]>0){
                rearranged[positiveindex]=nums[i];
                positiveindex+=2;
            }else{
                rearranged[negativeindex]=nums[i];
                negativeindex+=2;
            }
        }
        return rearranged;
    }
};