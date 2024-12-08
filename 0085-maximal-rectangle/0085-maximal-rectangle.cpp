class Solution {
public:
int larhis(vector<int> &arr){
    int n=arr.size();
    stack<int> st;
    int maxarea=0,element=0,nse=0,pse=0;
    for(int i=0;i<n;i++){
      while(!st.empty() && arr[st.top()]>arr[i]){
        element=st.top();
        st.pop();
        nse=i;
        pse=st.empty()?-1:st.top();
        maxarea=max(maxarea,(arr[element]*(nse-pse-1)));
      }
      st.push(i);
    }
    while(!st.empty()){
        nse=n;
        element=st.top();st.pop();
        pse=st.empty()?-1:st.top();
        maxarea=max(maxarea,(arr[element]*(nse-pse-1)));
    }
    return maxarea;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxarea=0;
      vector<int> presum(m, 0);
      
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(matrix[i][j]=='1'){
                presum[j]+=1;
            }else{
                presum[j]=0;
            }
        }
        maxarea=max(maxarea,larhis(presum));
        }
       
       
       return maxarea;

    }
};