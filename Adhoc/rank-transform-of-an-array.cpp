// https://leetcode.com/problems/rank-transform-of-an-array/?envType=daily-question&envId=2024-10-02

// TC: O(NlogN) | SC: O(N)
// hashmap based solution
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int N = arr.size();
        vector<pair<int, int>> sortedArr(N);
        for (int idx = 0; idx < N; idx++) {
            sortedArr[idx] = make_pair(arr[idx], idx);
        }
        
        // sort in non-decreasing order
        sort(sortedArr.begin(), sortedArr.end());
        
        int rank = 1;
        for (int idx = 0; idx < N; idx++) {
            pair<int, int> p = sortedArr[idx];
            arr[p.second] = rank;
            if ((idx + 1) < N) {
                pair<int, int> p2 = sortedArr[idx + 1];
                if (p2.first != p.first) rank += 1;
            }
        }
        
        return arr;
    }
};