// https://leetcode.com/problems/rotating-the-box/

// Normal implementation problem
// Time: O(rows * cols) | Space: O(rows * cols)

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size();
        int cols = box[0].size();
        
        vector<vector<char>> answer(cols, vector<char>(rows));
        
        for (int xc = 0, row = rows - 1; row >= 0; row--,xc++) {
            int stones = 0;
            int empties = 0;
            int start = 0;
            
            for (int col = 0; col < cols; col++) {
                if (box[row][col] == '#') stones += 1;
                else if (box[row][col] == '.') empties += 1;
                if (box[row][col] == '*' || col == cols - 1) {
                    for (int xr = start; xr <= col; xr++) {
                        if (empties != 0) {
                            answer[xr][xc] = '.';
                            empties -= 1;
                        }  else if (stones != 0) {
                            answer[xr][xc] = '#';
                            stones -= 1;
                        } else {
                            answer[xr][xc] = '*';
                        }
                    }
                    
                    // reset everything for next time
                    stones = 0;
                    empties = 0;
                    start = col + 1;
                }
            }
        }
        
        return answer;
    }
};