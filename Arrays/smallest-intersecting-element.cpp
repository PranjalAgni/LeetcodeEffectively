int solve(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) return -1;
    int cols = matrix[0].size();
    set<int> hashSet;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            hashSet.insert(matrix[row][col]);
        }
    }

    for (int val : hashSet) {
        bool isFound = true;
        for (int row = 0; row < rows; row++) {
            vector<int> data = matrix[row];
            isFound = binary_search(data.begin(), data.end(), val);
            if (!isFound) {
                break;
            }
        }

        if (isFound) return val;
    }

    return -1;
}