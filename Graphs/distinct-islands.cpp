// Time: O(V + E)
// V is total number of verticies
// E is total number of edges
void dfs(vector<vector<int>>& matrix, int x, int y, int parentX, int parentY,
         vector<pair<int, int>>& vp) {
    if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[x].size() ||
        matrix[x][y] != 1)
        return;

    matrix[x][y] *= -1;
    vp.push_back({x - parentX, y - parentY});
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (vector<int> dir : dirs) {
        dfs(matrix, x + dir[0], y + dir[1], parentX, parentY, vp);
    }
}

// Time: O(rows * cols) | Space: O(rows * cols)
int getUniqueShapedIsland(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    set<vector<pair<int, int>>> uniqueIslandSet;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (matrix[row][col] != 1) continue;
            vector<pair<int, int>> vp;
            dfs(matrix, row, col, row, col, vp);
            uniqueIslandSet.insert(vp);
        }
    }

    return uniqueIslandSet.size();
}

int solve(vector<vector<int>>& matrix) { return getUniqueShapedIsland(matrix); }