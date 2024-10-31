// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/
// Clean BFS approach O(V + E) where E = 3

// Time: O(N) | Space: O(N)
class Solution {
private:
    bool isValid(int row, int col, int& rows, int& cols) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) return false;
        return true;
    }
    
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& cache, int& rows, int&     cols) {
        int answer = 0;
        queue<vector<int>> q;
        for (int row = 0; row < rows; row++) {
            q.push({row, 0, 0});
        }
        
        vector<vector<int>> directions = {{-1, 1}, {0, 1}, {1, 1}};
        
        while(!q.empty()) {
            vector<int> entry = q.front();
            q.pop();
            if (cache[entry[0]][entry[1]] == 1) continue;
            cache[entry[0]][entry[1]] = 1;
            answer = max(answer, entry[2]);
            for (vector<int>& dir: directions) {
                int newRow = entry[0] + dir[0];
                int newCol = entry[1] + dir[1];
                if (isValid(newRow, newCol, rows, cols) && cache[newRow][newCol] == 0 && grid[newRow][newCol] > grid[entry[0]][entry[1]]) {
                    q.push({newRow, newCol, entry[2] + 1});
                }
            }
        }
        return answer;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> cache(rows, vector<int>(cols, 0));
        
        return bfs(grid, cache, rows, cols);
    }
};
