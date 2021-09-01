#include <vector>
using namespace std;

// Time: O(N * log(M)) | Space: O(1)
// N = max number of rows
// M = max number of cols
vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int row = 0; row < rows; row++) {
        int start = 0;
        int end = cols - 1;
        if (matrix[row][0] > target || matrix[row][end] < target) continue;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (matrix[row][mid] == target)
                return {row, mid};
            else if (matrix[row][mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return {-1, -1};
}
