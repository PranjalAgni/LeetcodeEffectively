// https://leetcode.com/problems/move-pieces-to-obtain-a-string/?envType=daily-question&envId=2024-12-05
class Solution {
public:
    bool canChange(string start, string target) {
        int N = start.length();
        int M = target.length();
        
        return N == M;
    }
};

/**

_L__R__R_
L______RR

_RL_ 
_LR_
**/