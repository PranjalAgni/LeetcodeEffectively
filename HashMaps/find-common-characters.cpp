class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> hashMap;
        
        bool isFirst = true;
        for (string& word: words) {
          unordered_map<char, int> freqMap;
          for (char& ch: word) {
            freqMap[ch] += 1;
          }
          
          if (!isFirst) {
            for (char& ch: word) hashMap[ch] = min(hashMap[ch], freqMap[ch]);  
          }
          
          if (isFirst) {
            isFirst = false;
            hashMap = freqMap;
          }
        }
        
        vector<string> answer;
        for (auto& [key, val]: hashMap) {
          cout << key << " " << val << endl;
          while(val-- > 0) answer.push_back(string(1, key));
        }
      
        return answer;
    }
};