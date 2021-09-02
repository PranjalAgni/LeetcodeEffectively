#include <vector>
using namespace std;

// Time: O(N + M) | Space: O(1)
// N = number of rows
// M = number of cols
vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int row = 0;
    int col = cols - 1;
    while (row < rows && col >= 0) {
        int curr = matrix[row][col];
        if (target == curr)
            return {row, col};
        else if (target > curr)
            row += 1;
        else
            col -= 1;
    }
    return {-1, -1};
}
