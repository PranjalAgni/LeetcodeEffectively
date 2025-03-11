// https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii
class Solution {
    private:
        bool isVowel(char& ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        }
    
        bool isValid(vector<int>& letters, int& k) {
            int totalVowels = 0;
            int consonants = 0;
            for (char ch = 'a'; ch <= 'z'; ch++) {
                int idx = ch - 'a';
                if (isVowel(ch)) {
                    if (letters[idx] > 0) totalVowels += 1;
                } else {
                    if (letters[idx] > 0) consonants += letters[idx];
                }
            }
    
            return totalVowels == 5 && consonants >= k;
            
        }
        // computes total substrings having each vowel atleast once and atleast k consonants
        long long computeTotalSubstrings(string& word, int k) {
            int N = word.length();
            int left = 0;
            int right = 0;
            vector<int> letters(26, 0);
            long long answer = 0;
    
            while (right < N) {
                letters[word[right] - 'a'] += 1;
                while (isValid(letters, k)) {
                    // this takes care of counting all the substrings
                    answer += N - right;
                    letters[word[left] - 'a'] -= 1;
                    left += 1;
                }
    
                right += 1;
            }
    
            return answer;
        }
    public:
        long long countOfSubstrings(string word, int k) {
            // we can compute the answer using this analogy
            // exactly(k) = atleast(k) - atleast(k + 1)
            // explanation:
            // atleast(k) = (k + 0) + (k + 1) + (k + 2) + ... (k + x)
            // atleast(k + 1) = (k + 1) + (k + 2) + (k + 3) + ... (k + x)
            // so exactly(k) will always have substrings with k consonants
            return computeTotalSubstrings(word, k) - computeTotalSubstrings(word, k + 1);
        }
    };
    