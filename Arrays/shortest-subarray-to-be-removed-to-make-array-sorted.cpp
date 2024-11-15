// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/?envType=daily-question&envId=2024-11-15
// Time: O(N) | Space: O(1)

// Nice 2 pointers based solution
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int N = arr.size();
        int left = 0;
        int right = N - 1;
        while ((left + 1) < N && arr[left] <= arr[left + 1]) {
            left += 1;
        }
        
        if (left == N - 1) return 0;
        
        while ((right - 1) >= 0 && arr[right - 1] <= arr[right]) {
            right -= 1;
        }
                
        int answer = min(N - left - 1, right);
        
        int pos = 0;
        while (pos <= left && right < N) {
            if (arr[pos] <= arr[right]) {
                answer = min(answer, right - pos - 1);
                pos += 1;
            } else {
                right += 1;
            }
        }
        
        return answer;
    }
};