// https://leetcode.com/problems/my-calendar-i/

class MyCalendar {
public:
    vector<pair<int, int>> vp;
    MyCalendar() {
       vp = vector<pair<int, int>>();
    }
    
    // Time: O(N + K*logK) | Space: O(K)
    // N = total number of meetings time given
    // K = total number of meetings without double booking
    bool book(int start, int end) {
        int N = vp.size();
        for (int idx = 0; idx < N; idx++) {
          pair<int, int> current = vp[idx];
          if (start >= current.first && start < current.second) return false;
          if (current.first >= start && current.first < end) return false;
          
        }
        vp.push_back({start, end});
        if (N > 1) sort(vp.begin(), vp.end());
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */