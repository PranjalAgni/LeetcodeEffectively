// https://leetcode.com/problems/license-key-formatting/

class Solution {
private:
    bool isAlphabet(char ch) {
      return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
    }
  
    bool isDigit(char ch) {
      return (ch >= '0' && ch <= '9');    
    }
  
    string sanatizeLicenseKey(string& licenseKey) {
      int pos = 0;
      if (licenseKey[0] == '-') pos += 1;
      return licenseKey.substr(pos, licenseKey.length());
    }
public:
    // Time: O(N) | Space: O(N)
    string licenseKeyFormatting(string s, int k) {
        int N = s.length();
        int groupIdx = 0;
        string reformattedLicenseKey = "";
        int groupLimit = k;
        bool isLastCharValid = false;
      
        for (int idx = N - 1; idx >= 0; idx--) {
          char ch = s[idx];
          if (isAlphabet(ch) || isDigit(ch)) { 
             reformattedLicenseKey.insert(0, 1, toupper(ch));
             groupLimit -= 1;
             isLastCharValid = true;
          } else if (ch == '-' && groupIdx == 0 && groupLimit <= 0 && isLastCharValid) {
            reformattedLicenseKey.insert(0, 1, '-');
            groupIdx += 1;
            groupLimit = k;
            isLastCharValid = false;
          }
          
          if (groupLimit <= 0 && idx > 0 && isLastCharValid) {
             reformattedLicenseKey.insert(0, 1, '-');
             groupIdx += 1;
             groupLimit = k;
             isLastCharValid = false;
          }
        }
      
           return sanatizeLicenseKey(reformattedLicenseKey);
        
    }
};