// https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/

// TC: O(N) | SC: O(N)
class Solution {
private:
    int solve(vector<int>& ride1, vector<int>& duration1, vector<int>& ride2, vector<int>& duration2) {
        int N = duration1.size();
        int M = duration2.size();
        int finish1 = INT_MAX;
        int finish2 = INT_MAX;
        
        for (int idx = 0; idx < N; idx++) {
            finish1 = min(finish1, ride1[idx] + duration1[idx]);
        }

        for (int idx = 0; idx < M; idx++) {
            finish2 = min(finish2, max(finish1, ride2[idx]) + duration2[idx]);
        }

        return finish2;
    }
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int N = landStartTime.size();
        int M = waterStartTime.size();
        int answer1 = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int answer2 = solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(answer1, answer2);
    }
};

