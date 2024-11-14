class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int l = 1, r = *max_element(quantities.begin(), quantities.end());
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            int requiredStores = 0;
            for (int i = 0; i < m; ++i) {
                requiredStores += (quantities[i] + mid - 1) / mid;
            }
            if (requiredStores <= n) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
