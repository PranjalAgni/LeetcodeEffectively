class Solution {
   public:
    string decodeAtIndex(string S, int K) {
        int len = S.length();
        string ans = "";
        long long totalLen = 0;

        for (int idx = 0; idx < len; idx++) {
            char ch = S[idx];
            if (isalpha(ch)) {
                totalLen += 1;
            } else {
                int digit = ch - '0';
                totalLen = totalLen * digit;
            }
        }

        for (int idx = len - 1; idx >= 0; idx--) {
            K = K % totalLen;
            char ch = S[idx];
            if (K == 0 && isalpha(ch)) {
                ans += ch;
                break;
            }

            if (!isalpha(ch)) {
                int digit = ch - '0';
                totalLen /= digit;
            } else {
                totalLen -= 1;
            }
        }
        return ans;
    }
};
