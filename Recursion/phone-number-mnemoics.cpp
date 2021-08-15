#include <vector>
using namespace std;

string getMapping(int digit) {
    vector<string> mappings = {"abc", "def",  "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};
    return mappings[digit - 2];
}

void generatePhoneNumbers(vector<string>& answer, string current,
                          string phoneNum, int pos) {
    if (current.length() == phoneNum.length()) {
        return answer.push_back(current);
    }

    int digit = phoneNum[pos] - '0';

    if (digit == 0 || digit == 1) {
        current += phoneNum[pos];
        generatePhoneNumbers(answer, current, phoneNum, pos + 1);
    } else {
        string mapping = getMapping(digit);
        for (int idx = 0; idx < mapping.length(); idx++) {
            current.push_back(mapping[idx]);
            generatePhoneNumbers(answer, current, phoneNum, pos + 1);
            current.pop_back();
        }
    }
}

vector<string> phoneNumberMnemonics(string phoneNumber) {
    vector<string> answer;
    generatePhoneNumbers(answer, "", phoneNumber, 0);
    return answer;
}
