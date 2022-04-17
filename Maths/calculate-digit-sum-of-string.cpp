class Solution {
private:
    // Time: O(N) | Space: O(N)
    // N = length of string
    vector<string> divideInChunksOfK(string& str, int k) {
      int N = str.length();
      vector<string> chunks;
      int pos = 0;
      string current = "";
      while (pos < N) {
        current.push_back(str[pos]);
        if (current.size() == k) {
          chunks.push_back(current);
          current = "";
        }
        pos += 1;
      }
      
      if (current.size() > 0) chunks.push_back(current);
      return chunks;
    }
    
    // Time: O(N) | Space: O(1)
    // N = length of number
    int getStringSum(string& number) {
      int sum = 0;
      for (char num: number) {
        sum += (num - '0');
      }
      
      return sum;
    }
public:
    // Time: O(N * N) | Space: O(N)
    // N = length of string
    string digitSum(string s, int k) {
      int N = s.length();
      if (k >= N) return s;
      while (s.length() > k) {
          vector<string> chunks = divideInChunksOfK(s, k);
          string answer = "";
          for (string& chunk: chunks) {
            int sum = getStringSum(chunk);
            answer += to_string(sum);
          }
        
          s = answer;
      }
      
      return s;
    }
};