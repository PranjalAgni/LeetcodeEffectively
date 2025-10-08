// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

// Time: O(M*log(M)) + N*log(M) | Space: O(N)
// N = len(spells)
// M = len(potions)
class Solution {
private:
    int binarySearch(vector<int>& potions, int& M, int current, long long& success) {
        int left = 0;
        int right = M;

        int ans = -1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            long long prod = (long long) potions[mid] * current;
            if (prod >= success) {
                ans = mid;
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int N = spells.size();
        int M = potions.size();

        sort(potions.begin(), potions.end());

        vector<int> answer;

        for (int& spell: spells) {
            int index = binarySearch(potions, M, spell, success);
            if (index == -1) answer.push_back(0);
            else {
                answer.push_back(M - index);
            }
        }

        return answer;
    }
};