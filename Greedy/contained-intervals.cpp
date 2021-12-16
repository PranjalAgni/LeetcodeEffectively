bool comparatorFn(vector<int>& intervalA, vector<int>& intervalB) {
    return (intervalA[1] == intervalB[1]) ? (intervalA[0] > intervalB[0]) : intervalA[1] < intervalB[1];
}

// Time: O(N * log(N)) | Space: O(1)
bool solve(vector<vector<int>>& intervals) {
    int N = intervals.size();
    if (N == 1) return false;
    sort(intervals.begin(), intervals.end(), comparatorFn);
    for (int idx = 1; idx < N; idx++) {
        vector<int>&  intervalA = intervals[idx - 1];
        vector<int>& intervalB = intervals[idx];
        if ((intervalA[0] >= intervalB[0] && intervalA[1] <= intervalB[1])) return true;
    }
    
    return false;
}