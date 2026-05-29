// https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/

// Time: O(N*L) | Space: O(1)
// L = length of largest num in nums
class Solution {
private:
    int getSum(int elt) {
        int sum = 0;
        while (elt != 0) {
            sum += elt % 10;
            elt /= 10;
        }
        return sum;
    }
public:
    int minElement(vector<int>& nums) {
        int N = nums.size();
        int answer = INT_MAX;
        for (int& num: nums) {
            answer = min(answer, getSum(num));
        }

        return answer;
    }
};