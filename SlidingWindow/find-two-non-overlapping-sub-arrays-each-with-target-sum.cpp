// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/?envType=daily-question&envId=2026-09-17

// Time: O(N) | Space: O(1)
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int N = arr.size();
        int currentSum = 0;
        int left = 0;
        int right = 0;
        vector<int> best(N, INT_MAX);
        int answer = INT_MAX;

        while (right < N) {
            currentSum += arr[right];

            while (currentSum > target && left <= right) {
                currentSum -= arr[left];
                left += 1;
            }

            // Carry forward the shortest subarray found so far.
            if (right > 0) {
                best[right] = best[right - 1];
            }

            if (currentSum == target) {
                int windowLen = right - left + 1;
                if (left > 0 && best[left - 1] != INT_MAX) {
                    answer = min(answer, best[left - 1] + windowLen);
                }
                best[right] = min(best[right], windowLen);

            }

            right += 1;
        }

        return answer == INT_MAX ? -1 : answer;

    }
};

