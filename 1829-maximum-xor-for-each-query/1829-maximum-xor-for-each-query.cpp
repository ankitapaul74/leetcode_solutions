class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int>res;
        int XOR=0;
        for(int i=0;i<n;i++){
            XOR^=nums[i];
        }
        int mask=(1<<maximumBit) -1;
        for(int i=0;i<n;i++){
            int k=XOR^mask;
            res.push_back(k);
            XOR^=nums[n-i-1];
        }
        return res;
    }
};