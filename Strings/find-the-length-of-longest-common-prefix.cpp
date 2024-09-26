// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/

class Solution {
private:
    int getLength(int& num) {
        string str = to_string(num);
        return str.length();
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int N = arr1.size();
        unordered_set<int> prefixSet;
        for (int& elt: arr1) {
            while (elt != 0) {
                prefixSet.insert(elt);
                elt /= 10;
            }
        }
        
        int answer = 0;
        for (int& elt: arr2) {
            while (elt != 0) {
                if (prefixSet.find(elt) != prefixSet.end()) {
                    answer = max(answer, getLength(elt));
                    break;
                }
                
                elt /= 10;
            }
        }
        
        return answer;
    }
};
