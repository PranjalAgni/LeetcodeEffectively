// https://leetcode.com/problems/minimum-number-of-people-to-teach/

class Solution {
private:
    vector<unordered_set<int>> buildWithLanguages(vector<vector<int>>& languages) {
        int M = languages.size();
        vector<unordered_set<int>> known(M + 1);
        for (int idx = 1; idx <= M; idx++) {
            for (int& lang: languages[idx - 1]) {
                known[idx].insert(lang);
            }
        }

        return known;
    }

    bool intersection(unordered_set<int>& A, unordered_set<int>& B) {
        if (A.size() > B.size()) return intersection(B, A);
        // always smaller one is A
        for (int lang: A) {
            if (B.count(lang)) return true;
        }

        return false;
    }

public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int M = languages.size();
        vector<unordered_set<int>> personWithLanguages = buildWithLanguages(languages);

        unordered_set<int> needToTaught;
        needToTaught.reserve(501);

        for (vector<int>& f: friendships) {
            int u = f[0];
            int v = f[1];
            // means they know a common lang
            if (intersection(personWithLanguages[u], personWithLanguages[v])) continue;
            needToTaught.insert(u);
            needToTaught.insert(v);
        }

        if (needToTaught.size() == 0) return 0;

        int answer = INT_MAX;

        for (int lang = 1; lang <= n; lang++) {
            int count = 0;
            for (const int& idx: needToTaught) {
                if (personWithLanguages[idx].count(lang) == 0) {
                    count += 1;
                }
            }

            answer = min(answer, count);
        }

        return answer;
    }
};