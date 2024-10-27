class Solution {
public:
    int countSquares(std::vector<std::vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 1) {
                    int maxSize = std::min(rows - i, cols - j);
                    for (int size = 1; size <= maxSize; ++size) {
                        bool isSquare = true;
                        for (int x = i; x < i + size; ++x) {
                            for (int y = j; y < j + size; ++y) {
                                if (matrix[x][y] == 0) {
                                    isSquare = false;
                                    break;
                                }
                            }
                            if (!isSquare) break;
                        }
                        if (isSquare) ans++;
                        else break;
                    }
                }
            }
        }
        
        return ans;
    }
};
