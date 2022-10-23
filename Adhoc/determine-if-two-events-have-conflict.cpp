// https://leetcode.com/contest/weekly-contest-316/problems/determine-if-two-events-have-conflict/

class Solution {
private:
    int convertTimeToMinutes(string& time) {
      string token = "";
      vector<string> tokens;
      
      // length of time string is 5 "HH:MM" format
      for (char& t: time) {
        if (t == ':') {
          tokens.push_back(token);
          token = "";
        } else {
          token += t;
        }
      }
      
      if (token.length()) tokens.push_back(token);
      
      return stoi(tokens[0]) * 60 + stoi(tokens[1]);
    }
  
    vector<int> getParsedTime(vector<string>& eventTime) {
      vector<int> time;
      // length of event time list is 2
      for (string& event: eventTime) {
          int minutes = convertTimeToMinutes(event);
          time.push_back(minutes);
      }
      
      return time;
    }
  
public:
    // Time: O(1) | Space: O(1)
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        vector<int> start = getParsedTime(event1);
        vector<int> end = getParsedTime(event2);
        
        if (end[0] >= start[0] && end[0] <= start[1]) return true;
        if (start[0] >= end[0] && start[0] <= end[1]) return true;
        return false;
    }
};
