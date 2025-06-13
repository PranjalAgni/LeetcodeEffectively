// https://leetcode.com/problems/lexicographical-numbers/

// Time: O(n) | Space: O(log(n))
// Each number is visited exactly once. The total number of operations is proportional to the number of elements generated, which is n.
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> answer;
        for (int num = 1; num <= 9; num++) {
            lexicalOrderRecursive(num, n, answer);
        }

        return answer;
    }

    void lexicalOrderRecursive(int start, int n, vector<int>& answer) {
       if (start > n) return;
       answer.push_back(start);
       for (int digit = 0; digit <= 9; digit++) {
            int num = start * 10 + digit;
            if (num > n) break;
            lexicalOrderRecursive(num, n, answer);
       }
    }
};