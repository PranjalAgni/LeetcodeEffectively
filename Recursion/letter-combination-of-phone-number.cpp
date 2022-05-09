// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
private:
  string getMapping(int digit) {
    vector<string> mappings = {"abc", "def",  "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};
    
    return mappings[digit - 2];
  }
  
  // Time: O(4^N * N) | Space: O(N)
  // where N <= 4 always as there can be max possible 4 characters for digits 7("pqrs") & 9("wxyz")
  void generatePhoneNumbers(vector<string>& answer, string current, string phoneNumber, int pos) {
    if (current.length() == phoneNumber.length()) {
      return answer.push_back(current);
    }
    int digit = phoneNumber[pos] - '0';
    string mapping = getMapping(digit);
    for (int idx = 0; idx < mapping.length(); idx++) {
      current.push_back(mapping[idx]);
      generatePhoneNumbers(answer, current, phoneNumber, pos + 1);
      current.pop_back();
    }
  }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        if (digits.length() == 0) return answer;
        generatePhoneNumbers(answer, "", digits, 0);
        return answer;
    }
};