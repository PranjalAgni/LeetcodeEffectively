// https://leetcode.com/problems/unique-3-digit-even-numbers/

// Time: O(N) | Space: O(N)
class Solution {
private:
    int fact(int x) {
        int prod = x;
        for (int p = x - 1; p >= 1; p--) {
            prod *= p;
        }

        return prod;
    }
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int, int> freqMap;
        for (int& d: digits) {
            freqMap[d] += 1;
        }

        int cnt = 0;
        for (auto& it: freqMap) {
            if (it.second == 1) {
                cnt += 1;
            }
        }

        if (cnt < 3) return cnt;

        return fact(cnt) / 6;
    }
};


// 1,2,3,4
// 123
// 134
// 


