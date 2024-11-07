// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/

// If two numbers in candidates have i'th bit set it means their AND will always be greater then 0
// Integers are 32 bits
// we can iterate over 32 bits
// find combinations of candidates in which all of them have same ith bit
// count and store the max so far candidates found

// Time: O(N) | Space: O(1)
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int answer = 0;
        for (int bit = 0; bit < 32; bit++) {
            int cnt = 0;
            for (int& num: candidates) {
                if (num & (1 << bit)) {
                    cnt += 1;
                }
            }
            
            answer = max(answer, cnt);
        }
        
        return answer;
    }
};