// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/

// Time: O(m * n) | Space: O(m * n)
// Good implementation based problem
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        for (vector<int>& wall: walls) {
            grid[wall[0]][wall[1]] = 1;
        }
        
        for (vector<int>& guard: guards) {
            grid[guard[0]][guard[1]] = 2;
        }
        
        
        int blockedCells = 0;
        for (vector<int>& guard: guards) {
            int row = guard[0];
            int col = guard[1];
            // cardinally in four directions guard can see
            // north
            for (int xr = row - 1; xr >= 0; xr--) {
                if (grid[xr][col] == 1 || grid[xr][col] == 2) break;
                if (grid[xr][col] == 0) {
                    grid[xr][col] = -1;
                    blockedCells += 1;
                }
            }
            // south
            for (int xr = row + 1; xr < m; xr++) {
                if (grid[xr][col] == 1 || grid[xr][col] == 2) break;
                if (grid[xr][col] == 0) {
                    grid[xr][col] = -1;
                    blockedCells += 1;
                }
            }
            // west
            for (int xc = col - 1; xc >= 0; xc--) {
                if (grid[row][xc] == 1 || grid[row][xc] == 2) break;
                if (grid[row][xc] == 0) {
                    grid[row][xc] = -1;
                    blockedCells += 1;
                }
            }
            // east
            for (int xc = col + 1; xc < n; xc++) {
                if (grid[row][xc] == 1 || grid[row][xc] == 2) break;
                if (grid[row][xc] == 0) {
                    grid[row][xc] = -1;
                    blockedCells += 1;
                }
            }
        }
        
        return (n*m) - blockedCells - walls.size() - guards.size();
    }
};