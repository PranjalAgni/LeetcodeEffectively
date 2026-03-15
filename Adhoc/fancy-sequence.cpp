// https://leetcode.com/problems/fancy-sequence/

class Fancy {
private:
    vector<long long> data;
    int pos;
    int N;
    int MOD;
public:
    Fancy() {
        N = int(1e5);
        data = vector<long long>(N, 0);
        pos = -1;
        MOD = int(1e9) + 7;
    }
    
    void append(int val) {
        pos += 1;
        data[pos] = val;
    }
    
    void addAll(int inc) {
        if (pos < 0) return;
        for (int idx = 0; idx <= pos; idx++) {
            data[idx] += (inc % MOD);
        }
    }
    
    void multAll(int m) {
        if (pos < 0) return;
        for (int idx = 0; idx <= pos; idx++) {
            data[idx] *= m;
            data[idx] %= MOD;
        }
    }
    
    int getIndex(int idx) {
        return idx > pos ? -1 : (data[idx] % MOD);
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */