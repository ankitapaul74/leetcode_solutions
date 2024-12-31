class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((i!=j)&& (0<=i && j<n) && arr[i]==2*arr[j]){
                    return true;
                }
            }
        }
        return false;
    }
};