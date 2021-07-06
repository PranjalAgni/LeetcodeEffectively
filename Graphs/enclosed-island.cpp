bool isValid(vector<vector<int>>& grid, int currRow, int currCol) {
    if (currRow < 0 || currRow >= grid.size() || currCol < 0 ||
        currCol >= grid[currRow].size())
        return false;
    return true;
}

void dfs(vector<vector<int>>& grid, int currRow, int currCol, int& nodes,
         bool& isOffGrid) {
    if (!isValid(grid, currRow, currCol)) {
        isOffGrid = true;
        return;
    }

    if (grid[currRow][currCol] != 1) return;

    grid[currRow][currCol] = 0;

    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (vector<int> dir : directions) {
        int newRow = currRow + dir[0];
        int newCol = currCol + dir[1];
        dfs(grid, newRow, newCol, nodes, isOffGrid);
    }

    nodes += 1;
}

int solve(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int ans = 0;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (matrix[row][col] == 1) {
                int nodes = 0;
                bool isOffGrid = false;
                dfs(matrix, row, col, nodes, isOffGrid);
                if (!isOffGrid) ans += nodes;
            }
        }
    }

    return ans;
}