// https://leetcode.com/problems/reconstruct-itinerary/

class Solution {
private:
    void reconstructItinerary(unordered_map<string, multiset<string>>& hashMap, string source, vector<string>& answer) {
      while (!hashMap[source].empty()) {
        string dest = *hashMap[source].begin();
        hashMap[source].erase(hashMap[source].begin());
        reconstructItinerary(hashMap, dest, answer);
      } 
      answer.push_back(source);
    }
public:
    // Time: O(N*log(N))
    // N = total number of tickets
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> hashMap;
        for (vector<string>& ticket: tickets) {
          multiset<string> destinations = hashMap[ticket[0]];
          destinations.insert(ticket[1]);
          hashMap[ticket[0]] = destinations;
        }
      
        vector<string> answer;
        reconstructItinerary(hashMap, "JFK", answer);
        reverse(answer.begin(), answer.end());
        return answer;
    }
};