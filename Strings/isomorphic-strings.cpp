class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        int N = s.length();
        int M = t.length();

        if (N != M) return false;

        unordered_map<char, char> hashMap;
        unordered_map<char, int> usedMap;

        for (int idx = 0; idx < N; idx++) {
            char curr = s[idx];
            char tar = t[idx];

            if (hashMap.find(curr) == hashMap.end()) {
                if (usedMap[tar]) return false;
                hashMap[curr] = tar;
            }

            char mappedVal = hashMap[curr];
            usedMap[tar] = true;
            if (mappedVal != tar) return false;
        }

        return true;
    }
};