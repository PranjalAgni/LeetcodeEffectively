#include <vector>
using namespace std;

void dfs(vector<vector<int>>& grid, int currRow, int currCol) {
    if (currRow < 0 || currRow >= grid.size() || currCol < 0 ||
        currCol >= grid[currRow].size() || grid[currRow][currCol] != 1)
        return;

    grid[currRow][currCol] = -1;

    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (vector<int> dir : directions) {
        dfs(grid, currRow + dir[0], currCol + dir[1]);
    }
}

// Time: O(rows * cols) | Space: O(rows * cols)
vector<vector<int>> removeIslands(vector<vector<int>> grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    for (int row = 0; row < rows; row++) {
        if (grid[row][0] == 1) {
            dfs(grid, row, 0);
        }

        if (grid[row][cols - 1] == 1) {
            dfs(grid, row, cols - 1);
        }
    }

    for (int col = 0; col < cols; col++) {
        if (grid[0][col] == 1) {
            dfs(grid, 0, col);
        }

        if (grid[rows - 1][col] == 1) {
            dfs(grid, rows - 1, col);
        }
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (grid[row][col] == 1) grid[row][col] = 0;
            if (grid[row][col] == -1) grid[row][col] = 1;
        }
    }

    return grid;
}
