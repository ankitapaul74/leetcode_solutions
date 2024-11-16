class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<=n-k;i++){
            bool isConsecutive=true;
            for(int j=i;j<i+k-1;j++){
                if(nums[j]+1!=nums[j+1]){
                    isConsecutive=false;
                    break;
                }
            }
            if(isConsecutive){
                v.push_back(nums[i+k-1]);
            }else{
                v.push_back(-1);
            }
        }
        return v;
    }
};