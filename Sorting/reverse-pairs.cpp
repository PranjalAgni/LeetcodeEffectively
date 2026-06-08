// interesting problem
// good interview ask
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int N = nums.size();
        int answer = 0;
        for (int idx = 0; idx < N; idx++) {
            for (int jdx = idx + 1; jdx < N; jdx++) {
                if (nums[idx] > 2 * nums[jdx]) {
                    answer += 1;
                }
            }
        }

        return answer;
    }
};