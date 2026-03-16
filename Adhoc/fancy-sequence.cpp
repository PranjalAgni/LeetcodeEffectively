// https://leetcode.com/problems/fancy-sequence/

class Fancy { 
private:
    vector<long long> data;
    int MOD;
    struct Operation {
        int type;
        int val;
        int range;
    };
    vector<Operation> operations;
public:
    Fancy() {
        data = vector<long long>();
        operations = vector<Operation>();
        MOD = int(1e9) + 7;
    }
    
    void append(int val) {
        data.push_back(val);
    }
    
    void addAll(int inc) {
        int N = data.size();
        operations.push_back({1, inc, N});
    }

    void add(int pos, int inc, long long& answer) {
        answer += (inc % MOD);
    }
    
    void multAll(int m) {
        int N = data.size();
        operations.push_back({2, m, N});
    }

    void mult(int pos, int m, long long& answer) {
        answer *= (m % MOD);
        answer %= MOD;
    }
    
    int getIndex(int idx) {
        int N = data.size();
        if (idx >= N) return -1;
        return compute(idx);
    }

    int compute(int idx) {
        long long answer = data[idx];
        int N = data.size();
        for (Operation& op: operations) {
            if (idx >= op.range) {
                continue;
            }
            if (op.type == 1) {
                add(idx, op.val, answer);
            } else {
                mult(idx, op.val, answer);
            }
        }

        return answer % MOD;
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