class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int minAbsVal = INT_MAX;
        int negativeCount = 0;
        for (auto& row : matrix) {
            for (int val : row) {
                sum += abs(val);
                if (val < 0) {
                    negativeCount++;
                }
                minAbsVal = min(minAbsVal, abs(val));
            }
        }
        if (negativeCount % 2 != 0) {
            sum -= 2 * minAbsVal;
        }

        return sum;
    }
};