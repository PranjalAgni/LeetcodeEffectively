#include <vector>
using namespace std;

queue<vector<int>> getPositiveElements(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    queue<vector<int>> positiveElements;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (grid[row][col] > 0) {
                positiveElements.push({row, col});
            }
        }
    }

    return positiveElements;
}

bool isValid(vector<vector<int>>& grid, int currRow, int currCol) {
    if (currRow < 0 || currRow >= grid.size() || currCol < 0 ||
        currCol >= grid[currRow].size() || grid[currRow][currCol] >= 0)
        return false;
    return true;
}

void getAdjacentNegativeElements(vector<vector<int>>& grid, int currRow,
                                 int currCol,
                                 queue<vector<int>>& convertedPositives) {
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (vector<int> dir : directions) {
        int newRow = currRow + dir[0];
        int newCol = currCol + dir[1];
        if (isValid(grid, newRow, newCol)) {
            grid[newRow][newCol] *= -1;
            convertedPositives.push({newRow, newCol});
        }
    }
}

int performBFS(vector<vector<int>>& grid) {
    queue<vector<int>> positiveQueue = getPositiveElements(grid);
    int pass = 0;

    while (!positiveQueue.empty()) {
        int N = positiveQueue.size();

        while (N-- > 0) {
            vector<int> current = positiveQueue.front();
            positiveQueue.pop();
            getAdjacentNegativeElements(grid, current[0], current[1],
                                        positiveQueue);
        }

        pass += 1;
    }

    return pass;
}

bool containsNegative(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    for (int row = 0; row < rows; row++) {
        int start = 0;
        int end = cols - 1;

        while (start < end) {
            if (grid[row][start] < 0) return true;
            if (grid[row][end] < 0) return true;
            start += 1;
            end -= 1;
        }
    }

    return false;
}

int minimumPassesOfMatrix(vector<vector<int>> matrix) {
    int passes = performBFS(matrix);
    return containsNegative(matrix) ? -1 : passes - 1;
}
