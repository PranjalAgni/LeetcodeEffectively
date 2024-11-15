// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/?envType=daily-question&envId=2024-11-15
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int N = arr.size();
        int left = 0;
        int right = N - 1;
        while ((left + 1) < N && arr[left] <= arr[left + 1]) {
            left += 1;
        }
        // 1,3,4,5,6
        
        
        
        if (left == N - 1) return 0;
        
        while ((right - 1) >= 0 && arr[right - 1] <= arr[right]) {
            right -= 1;
        }
        
        
        // we have left and right
        
        cout << left << " " << right << endl;
        int answer = min(N - left - 1, right);
        
        int x = 0;
        while (x <= left && right < N) {
            if (arr[right] > arr[x]) {
                x += 1;
                answer = min(answer, right - 1);
            } else {
                right += 1;
            }
        }
        int temp = right;
        // check for right stretching
        while (temp < N && arr[left] > arr[temp]) {
            temp += 1;
        }
        
        int x = temp - left;
        
        temp = left;
        while (temp >= 0 && arr[temp] > arr[right]) {
            temp -= 1;
        }
        
        int y = right - temp;
        return min(x, y);
        
    }
};