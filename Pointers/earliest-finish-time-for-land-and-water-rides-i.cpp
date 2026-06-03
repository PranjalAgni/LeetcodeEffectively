// https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/

// this is brute force approach we will optimise it
class Solution {
public:
    // this is brute force solution
    // computing land ride completion then water ride completion
    // then computing in reverse order water ride completion then land ride completion
    // min time will be the answer
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int N = landStartTime.size();
        int M = waterStartTime.size();
        int answer = INT_MAX;
        for (int idx = 0; idx < N; idx++) {
            for (int jdx = 0; jdx < M; jdx++) {
                int finish1 = landStartTime[idx] + landDuration[idx];
                int land_water = max(finish1, waterStartTime[jdx]) + waterDuration[jdx];
                answer = min(answer, land_water);

                int finish2 = waterStartTime[jdx] + waterDuration[jdx];
                int water_land = max(finish2, landStartTime[idx]) + landDuration[idx];

                answer = min(answer, water_land);
            }
        }

        return answer;
    }
};


// use recursion here to compute all the possibilites?
// sort the array somehow and match then based on the start time