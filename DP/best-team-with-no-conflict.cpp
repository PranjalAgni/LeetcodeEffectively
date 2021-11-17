// https://leetcode.com/problems/best-team-with-no-conflicts/
class Solution {
   public:
    vector<pair<int, int>> buildSortedScoreAndAgesList(vector<int>& scores,
                                                       vector<int>& ages) {
        int N = scores.size();
        vector<pair<int, int>> scoreAge(N);
        for (int idx = 0; idx < N; idx++) {
            scoreAge[idx] = make_pair(ages[idx], scores[idx]);
        }

        sort(scoreAge.begin(), scoreAge.end());
        return scoreAge;
    }

    // Time: O(N * N) | Space: O(N)
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int N = scores.size();
        vector<pair<int, int>> scoreAge =
            buildSortedScoreAndAgesList(scores, ages);

        vector<int> teamScores(N);

        for (int idx = 0; idx < N; idx++) {
            pair current = scoreAge[idx];
            int score = current.second;
            teamScores[idx] = score;
            for (int jdx = 0; jdx < idx; jdx++) {
                if (score >= scoreAge[jdx].second) {
                    teamScores[idx] =
                        max(teamScores[idx], score + teamScores[jdx]);
                }
            }
        }

        int maxScore = teamScores[0];
        for (int idx = 1; idx < N; idx++) {
            maxScore = max(maxScore, teamScores[idx]);
        }

        return maxScore;
    }
};
