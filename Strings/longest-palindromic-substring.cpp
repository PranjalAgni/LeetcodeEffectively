using namespace std;

vector<int> getLongestPalindromeFrom(string& str, int leftIdx, int rightIdx) {
    int N = str.length();
    while (leftIdx >= 0 && rightIdx < N && str[leftIdx] == str[rightIdx]) {
        leftIdx -= 1;
        rightIdx += 1;
    }

    return {leftIdx + 1, rightIdx};
}

vector<int> getLongestLength(vector<int>& oddCentered,
                             vector<int>& evenCentered) {
    int oddVal = oddCentered[1] - oddCentered[0];
    int evenVal = evenCentered[1] - evenCentered[0];
    return (oddVal > evenVal) ? oddCentered : evenCentered;
}

// Time: O(N^2) | Space: O(N)
// Idea is to for every index, use 2 pointer approach to check if the left &
// right substring is palindrome There can be:
// 1. even length palindrome
// 2. odd length palindrome
// calculate both even and odd length palindrome for idx
// compare them and store the longest so far
// in the end we just need to return the substring based on the longest pair of
// index we got.
string longestPalindromicSubstring(string str) {
    int N = str.length();
    vector<int> currentLongest = {0, 1};

    for (int idx = 1; idx < N; idx++) {
        vector<int> oddCentered =
            getLongestPalindromeFrom(str, idx - 1, idx + 1);
        vector<int> evenCentered = getLongestPalindromeFrom(str, idx - 1, idx);
        vector<int> longest = getLongestLength(oddCentered, evenCentered);
        currentLongest = getLongestLength(currentLongest, longest);
    }

    return str.substr(currentLongest[0], currentLongest[1] - currentLongest[0]);
}
