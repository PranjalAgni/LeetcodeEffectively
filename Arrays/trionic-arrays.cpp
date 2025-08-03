// https://leetcode.com/problems/trionic-array-i/

// Time: O(N) | Space: O(1)

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int N = nums.size();
        int p = 0;

        // finding the p
        for (int idx = 1; idx < N; idx++) {
            if (nums[idx] <= nums[idx - 1]) {
                break;
            }

            p += 1;
        }

        if (p == 0) return false;
        
        // finding the q
        int q = p;
        for (int idx = p; idx < N - 1; idx++) {
            if (nums[idx] <= nums[idx + 1]) break;
            q += 1;
        }

        if (p == q || q == N - 1) return false;

        // checking the [q...N-1] part
        for (int idx = q + 1; idx < N; idx++) {
            if (nums[idx] <= nums[idx - 1]) return false;
        }
                
        return true;
    }
};