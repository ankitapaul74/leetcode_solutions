class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        int maxarea=0,element=0,pse=0,nse=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&& arr[st.top()]>arr[i]){
                element=st.top();
                st.pop();
                nse=i;
                pse=st.empty()?-1:st.top();
                maxarea=max(maxarea,(arr[element]*(nse-pse-1)));
            }
            st.push(i);
        }
        while(!st.empty()){
            element=st.top();
            st.pop();
            nse=n;
            pse=st.empty()?-1:st.top();
             maxarea=max(maxarea,(arr[element]*(nse-pse-1)));
        }
        return maxarea;
    }
};