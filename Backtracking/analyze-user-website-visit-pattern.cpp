// https://takeuforward.org/plus/dsa/problems/analyze-user-website-visit-pattern

// TC: O(N^3 log N) | SC: O(N^3)
class Solution {
private:
    void computePatterns(set<vector<string>>& answer, vector<string>& website, vector<string> current, int k, int pos) {

        if (current.size() == k) {
            answer.insert(current);
            return;
        }

        for (int idx = pos; idx < website.size(); idx++) {
            current.push_back(website[idx]);
            computePatterns(answer, website, current, k, idx + 1);
            current.pop_back();
        }
    }
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        
        unordered_map<string, vector<string>> userVsWebsiteVistMap;
        int N = username.size();
        for (int idx = 0; idx < N; idx++) {
            userVsWebsiteVistMap[username[idx]].push_back(website[idx]);
        }

        map<vector<string>, int> patternCount;

        for (auto const& it: userVsWebsiteVistMap) {
            set<vector<string>> pattern;
            vector<string> visited = it.second;
            computePatterns(pattern, visited, {}, 3, 0);

            for (const vector<string>& vv:  pattern ) {
                patternCount[vv] += 1;
            }
        }

        int highest = 0;
        vector<string> answer;

        for (const auto& it: patternCount) {
            if (it.second > highest) {
                highest = it.second;
                answer = it.first;
            }
        }

        return answer;
    }
};