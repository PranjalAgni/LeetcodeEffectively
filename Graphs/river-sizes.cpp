#include <vector>
using namespace std;

// Time: O(V + E) | Space: O(V)
void dfs(vector<vector<int>>& matrix, int currRow, int currCol, int& cnt) {
    if (currRow < 0 || currRow >= matrix.size() || currCol < 0 ||
        currCol >= matrix[currRow].size() || matrix[currRow][currCol] != 1)
        return;

    matrix[currRow][currCol] = 0;
    cnt += 1;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (vector<int> dir : dirs) {
        dfs(matrix, currRow + dir[0], currCol + dir[1], cnt);
    }
}
vector<int> riverSizes(vector<vector<int>> matrix) {
    vector<int> sizes;

    int rows = matrix.size();

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < matrix[row].size(); col++) {
            if (matrix[row][col] == 1) {
                int cnt = 0;
                dfs(matrix, row, col, cnt);
                sizes.push_back(cnt);
            }
        }
    }
    return sizes;
}
