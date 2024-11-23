class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<char>> rotated(cols, vector<char>(rows));

        for (int col = 0; col < cols; col++) {
            for (int row = 0; row < rows; row++) {
                rotated[col][row] = matrix[row][col];
            }
        }

        for (int col = 0; col < cols; col++) {
            for (int left = 0, right = rows - 1; left < right; left++, right--) {
                swap(rotated[col][left], rotated[col][right]);
            }
        }

        for (int col = 0; col < rows; col++) {
            for (int row = cols - 1; row >= 0; row--) {
                if (rotated[row][col] == '.') {
                    int pos = -1;
                    for (int prev = row - 1; prev >= 0; prev--) {
                        if (rotated[prev][col] == '*') break;
                        if (rotated[prev][col] == '#') {
                            pos = prev;
                            break;
                        }
                    }
                    if (pos != -1) {
                        rotated[pos][col] = '.';
                        rotated[row][col] = '#';
                    }
                }
            }
        }
        return rotated;
    }
};
