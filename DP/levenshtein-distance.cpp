using namespace std;

// Time: O(rows * cols) | Space: O(rows * cols)
int levenshteinDistance(string str1, string str2) {
    int rows = str1.length();
    int cols = str2.length();

    vector<vector<int>> dp(rows + 1, vector<int>(cols + 1));

    for (int row = 0; row <= rows; row++) {
        dp[row][0] = row;
    }

    for (int col = 0; col <= cols; col++) {
        dp[0][col] = col;
    }

    for (int row = 1; row <= rows; row++) {
        char char1 = str1[row - 1];
        for (int col = 1; col <= cols; col++) {
            char char2 = str2[col - 1];
            int cost = (char1 == char2) ? 0 : 1;
            int insertCost = 1 + dp[row - 1][col];
            int deletionCost = 1 + dp[row][col - 1];
            int replaceCost = cost + dp[row - 1][col - 1];
            dp[row][col] = min({insertCost, deletionCost, replaceCost});
        }
    }

    return dp[rows][cols];
}