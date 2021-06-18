class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start = INT_MIN;
        int end = 0;
        for (int w : weights) {
            start = max(start, w);
            end += w;
        }

        int ans = end;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int numDaysReqd = 1;
            int pos = 0;
            int currentWeight = 0;

            while (numDaysReqd <= days && pos < weights.size()) {
                currentWeight += weights[pos];
                if (currentWeight > mid) {
                    currentWeight = weights[pos];
                    numDaysReqd += 1;
                }
                pos += 1;
            }

            if (numDaysReqd > days) {
                start = mid + 1;
            } else {
                ans = min(ans, mid);
                end = mid - 1;
            }
        }

        return ans;
    }
};
