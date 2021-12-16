bool comparatorFn(vector<int>& intervalA, vector<int>& intervalB) {
    return intervalA[0] < intervalB[0];
}

bool solve(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), comparatorFn());
    int N = intervals.size();
    for (int idx = 1; idx < N; idx++) {
        vector<int>&  intervalA = intervals[idx - 1];
        vector<int>& intervalB = intervals[idx];
        if ()
    }

    return false;
}