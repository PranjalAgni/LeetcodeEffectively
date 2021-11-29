// https://leetcode.com/contest/weekly-contest-269/problems/removing-minimum-and-maximum-from-array/

class Solution {
   public:
    // Time: O(N) | Space: O(1)
    vector<int> getMinMaxIndex(vector<int>& nums, int& N) {
        int minElt = nums[0], maxElt = nums[0];
        int minIdx = 0, maxIdx = 0;

        for (int idx = 1; idx < N; idx++) {
            if (nums[idx] < minElt) {
                minElt = nums[idx];
                minIdx = idx;
            }

            if (nums[idx] > maxElt) {
                maxElt = nums[idx];
                maxIdx = idx;
            }
        }

        return {minIdx, maxIdx};
    }

    vector<int> computeDeletionOrder(int& minIdx, int& maxIdx, int& back) {
        int minDistanceToMinIdx = min(minIdx, (back - minIdx));
        int minDistanceToMaxIdx = min(maxIdx, (back - maxIdx));
        return (minDistanceToMinIdx < minDistanceToMaxIdx)
                   ? (vector<int>){minIdx, maxIdx}
                   : (vector<int>){maxIdx, minIdx};
    }

    int performDeletion(int& eltIdx, int& front, int& back) {
        int count = 0;
        if ((eltIdx - front) < (back - eltIdx)) {
            count = eltIdx - front + 1;
            front = eltIdx + 1;
        } else {
            count = back - eltIdx + 1;
            back = eltIdx - 1;
        }

        return count;
    }

    int minimumDeletions(vector<int>& nums) {
        int N = nums.size();

        if (N == 1) return 1;

        // get the min, max index
        vector<int> minMaxIndex = getMinMaxIndex(nums, N);
        int minIdx = minMaxIndex[0];
        int maxIdx = minMaxIndex[1];

        int front = 0;
        int back = N - 1;

        // which element to delete first based on which comes first from left
        // and right
        vector<int> deletionOrder = computeDeletionOrder(minIdx, maxIdx, back);

        // delete both the index and add the operations
        return performDeletion(deletionOrder[0], front, back) +
               performDeletion(deletionOrder[1], front, back);
    }
};