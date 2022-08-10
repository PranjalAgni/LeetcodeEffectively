class MyCalendar {
public:
    vector<pair<int, int>> vp;
    MyCalendar() {
       vp = vector<pair<int, int>>();
    }
    
    bool book(int start, int end) {
        int N = vp.size();
        for (int idx = 0; idx < N; idx++) {
          pair<int, int> current = vp[idx];
          // cout << "Pair " << current.first << "  " << current.second << endl;
          if (start >= current.first && start < current.second) return false;
        }
        
        vp.push_back({start, end});
        sort(vp.begin(), vp.end());
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */