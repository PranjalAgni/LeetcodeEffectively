class Solution {
   public:
    vector<string> buildArray(vector<int>& target, int n) {
        const string PUSH = "Push";
        const string POP = "Pop";
        vector<string> answer;
        int idx = 0;
        int len = target.size();
        for (int elt = 1; elt <= n && idx < len; elt++) {
            if (elt == target[idx]) {
                answer.push_back(PUSH);
                idx += 1;
            } else {
                answer.push_back(PUSH);
                answer.push_back(POP);
            }
        }

        return answer;
    }
};