#include <vector>
using namespace std;

// Time: O(2Klog2K) | Space: O(2*K)
vector<vector<int>> taskAssignment(int k, vector<int> tasks) {
    vector<pair<int, int>> vp(2 * k);

    for (int idx = 0; idx < 2 * k; idx++) {
        vp[idx] = {tasks[idx], idx};
    }

    sort(vp.begin(), vp.end());

    int start = 0;
    int end = 2 * k - 1;

    vector<vector<int>> answer;
    while (start < end) {
        answer.push_back({vp[start].second, vp[end].second});
        start += 1;
        end -= 1;
    }

    return answer;

    return {};
}
