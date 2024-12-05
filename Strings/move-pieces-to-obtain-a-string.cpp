// https://leetcode.com/problems/move-pieces-to-obtain-a-string/

// Time: O(N) | Space: O(1)
class Solution {
public:
    bool canChange(string start, string target) {
        int N = start.length();
        int M = target.length();
        if (N != M) return false;
        int spos = 0;
        int tpos = 0;
        
        while (spos < N || tpos < N) {
            while(spos < N && start[spos] == '_') spos += 1;
            while(tpos < N && target[tpos] == '_') tpos += 1;
            
            if (spos == N || tpos == N) {
                break;
            }
            
            if (start[spos] != target[tpos]) return false;   
            if (start[spos] == 'L' && spos < tpos) return false;
            if (start[spos] == 'R' && spos > tpos) return false;
            
            spos += 1;
            tpos += 1;
        }
        
        return spos == N && tpos == N;
        
    }
};
