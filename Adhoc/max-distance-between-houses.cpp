// https://leetcode.com/contest/weekly-contest-268/problems/two-furthest-houses-with-different-colors/

class Solution {
   public:
    void calculateDistance(vector<int>& colors, int left, int right,
                           int& answer, bool travelDirection) {
        while (left < right) {
            if (colors[left] != colors[right]) {
                answer = max(answer, right - left);
                break;
            } else {
                if (travelDirection == 1)
                    left += 1;
                else
                    right -= 1;
            }
        }

        return;
    }

    // Time: O(N) | Space: O(1)
    int maxDistance(vector<int>& colors) {
        int N = colors.size();
        int answer = 0;
        calculateDistance(colors, 0, N - 1, answer, 1);
        calculateDistance(colors, 0, N - 1, answer, 0);
        return answer;
    }
};