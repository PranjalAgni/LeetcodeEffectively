#include <vector>
using namespace std;

bool isValid(vector<vector<int>>& grid, int currRow, int currCol) {
    if (currRow < 0 || currRow >= grid.size() || currCol < 0) return false;
    return true;
}

void dfs(vector<vector<int>>& grid, int currRow, int currCol,
         vector<vector<int>>& hashMap, int& negativeNums) {
    if (!isValid(grid, currRow, currCol) || grid[currRow][currCol] <= 0 ||
        hashMap[currRow][currCol])
        return;
    hashMap[currRow][currCol] = 1;

    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (vector<int> dir : directions) {
        int newRow = currRow + dir[0];
        int newCol = currCol + dir[1];
        if (!isValid(grid, newRow, newCol)) continue;
        if (grid[newRow][newCol] < 0) {
            negativeNums += 1;
            grid[newRow][newCol] *= -1;
            hashMap[newRow][newCol] = 1;
        } else {
            dfs(grid, newRow, newCol, hashMap, negativeNums);
        }
    }
}

int getNegativeElements(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    int elts = 0;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (grid[row][col] < 0) elts += 1;
        }
    }

    return elts;
}

// Time: O(rows * cols) | Space: O(rows * cols)
int minimumPassesOfMatrix(vector<vector<int>> grid) {
    int totalNeg = getNegativeElements(grid);
    if (!totalNeg) return totalNeg;

    int rows = grid.size();
    int cols = grid[0].size();

    int pass = 0;

    while (totalNeg > 0) {
        int currentNegative = 0;
        vector<vector<int>> visitedMap(rows, vector<int>(cols, 0));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (!visitedMap[row][col] && grid[row][col] > 0) {
                    dfs(grid, row, col, visitedMap, currentNegative);
                }
            }
        }

        if (currentNegative == 0) break;

        totalNeg -= currentNegative;
        pass += 1;
    }

    return (totalNeg > 0) ? -1 : pass;
}