// https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/

// Time: O(N^2) | Space: O(N)
// This is a standard sliding window problem
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int N = nums.size();
        int left = 0;
        int right = N - 1;

        unordered_map<int, vector<int>> posMap;
        for (int idx = 0; idx < N; idx++) {
            posMap[nums[idx]].push_back(idx);
        }

        int answer = 0;
        for (int idx = 0; idx < N; idx++) {
            int a = nums[idx];
            for (int jdx = idx + 2; jdx < N; jdx++) {
                int b = nums[jdx];
                int toFind = (a + b) * 2;
                if (posMap.find(toFind) != posMap.end()) {
                    vector<int> allPos = posMap[toFind];
                    int c = 0;
                    for (int& p: allPos) {
                        if (p > idx && p < jdx) {
                            answer += 1;
                            // mark this removed so it will work
                            allPos[c] *= -1;
                        }
                        c += 1;
                    }
                    posMap[toFind] = allPos;
                }
            }
        }

        return answer;
    }
};