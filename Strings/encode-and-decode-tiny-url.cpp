// https://leetcode.com/problems/encode-and-decode-tinyurl/

class Solution {
public:
    // Time: O(1) | Space: O(N)
    unordered_map<string, string> tinyMap;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int keys = tinyMap.size() + 1;
        string encodedURL = to_string(keys);
        tinyMap[encodedURL] = longUrl;
        return encodedURL;
    }

    // Time: O(1) | Space: O(1)
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return tinyMap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));