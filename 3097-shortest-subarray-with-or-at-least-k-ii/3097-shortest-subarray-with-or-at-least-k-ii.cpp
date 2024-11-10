class Solution {
public:
    void func(int p, vector<int>& temp) {
        int i = 0;
        while (p) {
            temp[i] += (p & 1);
            p = p >> 1;
            i++;
        }
    }
    int func2(int p, vector<int>& temp, int c) {
        int i = 0;
        while (p) {
            if (temp[i] == 1 && (p & 1)) {
                c -= (1 << i);
            }
            temp[i] -= (p & 1);
            i++;
            p = p >> 1;
        }
        return c;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int c = 0, ans = INT_MAX, i = 0, j = 0;
        vector<int> temp(32, 0);
        while (i < n) {
            c |= nums[i];
            func(nums[i], temp);
            if (c >= k) {
                ans = min(ans, i - j + 1);
            }
            while (c >= k && j <= i) {
                ans = min(ans, i - j + 1);
                c = func2(nums[j], temp, c);
                j++;
            }
            i++;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
