// https://leetcode.com/problems/count-number-of-homogenous-substrings/?envType=daily-question

class Solution {
  public: int countHomogenous(string s) {
    int N = s.length();
    unordered_map < string, int > freqMap;
    string group = "";
    for (int idx = 0; idx < N; idx++) {
      cout << "g = " << group << endl;
      char ch = s[idx];
      string current = string(1, ch);
      freqMap[current] += 1;
      int groupLen = group.length();
      if (groupLen == 0) {
        group += current;
        continue;
      }

      string previous = string(1, group[groupLen - 1]);

      if (previous != current) {
        group = current;
      } else {
        group += current;
      }

      if (group.length() > 1) {
        freqMap[group] += 1;
      }
    }
    
    if (group.length() > 1) {
      freqMap[group] += 1;
    }
    
    int answer = 0;
    for (auto & data: freqMap) {
      answer += data.second;
    }

    return answer;

  }
};
