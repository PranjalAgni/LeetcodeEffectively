class Solution {
   public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int N = bloomDay.size();

        if ((m * k) > N) return -1;

        int low = bloomDay[0];
        int high = bloomDay[0];

        for (int elt : bloomDay) {
            low = min(low, elt);
            high = max(high, elt);
        }

        if (low == high) return low;

        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int formed = 0;
            int numBouquets = 0;

            for (int idx = 0; idx < N; idx++) {
                if (bloomDay[idx] > mid) {
                    formed = 0;
                } else {
                    formed += 1;
                    if (formed == k) {
                        numBouquets += 1;
                        formed = 0;
                    }
                }
            }

            if (numBouquets < m) {
                low = mid + 1;
            } else {
                ans = min(ans, mid);
                high = mid - 1;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};