// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

/**  This problem can be solved on this 2 line idea 💡
Assume the i-th row is an all-0s row after flipping x columns.

1. If there are any other all-0s row, say j-th row, then the j-th row before flipping should be the same as the i-th row.
2. If there are any other all-1s row, say k-th row, then the k-th row before flipping should be totally different from the i-th row.

Now this means we just need to get max of all the identical rows and all the totally different rows.
*/

// Time: O(rows * cols) | Space: O(rows * cols)
class Solution {
private:
    unordered_map<string, int> prepareCache(vector<vector<int>>& matrix) {
        unordered_map<string, int> cache;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int row = 0; row < rows; row++) {
            string key = "";
            for (int col = 0; col < cols; col++) {
                key += to_string(matrix[row][col]);
            }
            
            cache[key] += 1;
        }
        
        return cache;
    }
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        unordered_map<string, int> cache = prepareCache(matrix);
        int answer = 0;
         for (int row = 0; row < rows; row++) {
            string key1 = "";
            string key2 = "";
            
            for (int col = 0; col < cols; col++) {
                key1 += to_string(matrix[row][col]);
                int val = matrix[row][col] == 1 ? 0 : 1;
                key2 += to_string(val);
            }
            
            answer = max(answer, cache[key1] + cache[key2]);
        }
        
        return answer;
    }
};