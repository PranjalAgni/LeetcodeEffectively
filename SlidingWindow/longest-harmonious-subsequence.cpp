// https://leetcode.com/problems/longest-harmonious-subsequence/

// this problem is like a IQ test
// this is easy but the solution is creative
// also a reminder to read the problem statement carefully

// Time: O(n) | Space: O(n)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int, int> freqMap;
        for (int& num: nums) {
            freqMap[num] += 1;
        }

        int answer = 0;

        for (auto const& [key, value]: freqMap) {
            if (freqMap.find(key + 1) != freqMap.end()) {
                answer = max(answer, value + freqMap[key + 1]);
            }
        }

        return answer;
    }
};