class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int el;
       int count=0;
       for(int i=0;i<nums.size();i++){
        if(count==0){
            count=1;
            el=nums[i];
        }else if(nums[i]==el){
            count++;
        }else{
            count--;
        }
       }int count1=0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]==el){
            count1++;
        }
       }
       if(count1>(nums.size()/2)){
        return el;
       }
       return 0;
    }
};