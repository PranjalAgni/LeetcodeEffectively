// https://leetcode.com/problems/add-binary/

// Nice and clean technique to add binary strings with carry calculations
// TC: O(N) | SC: O(1)
class Solution {
public:
    string addBinary(string a, string b) {
        int N = a.length() - 1;
        int M = b.length() - 1;
        int carry = 0;
        string answer = "";
        while (N >= 0 || M >= 0 || carry > 0) {
            if (N >= 0) {
                carry += a[N] - '0';
                N -= 1;
            }
            if (M >= 0) {
                carry += b[M] - '0';
                M -= 1;
            }

            answer += (carry % 2) + '0';
            carry /= 2;
        }
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
};