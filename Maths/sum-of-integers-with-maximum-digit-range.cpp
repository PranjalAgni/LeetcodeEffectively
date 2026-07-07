// https://leetcode.com/contest/weekly-contest-509/problems/sum-of-integers-with-maximum-digit-range/

class Solution {
private:
    int getDigitRange(int num) {
        int smallest = INT_MAX;
        int largest = INT_MIN;
        while (num != 0) {
            int dig = num % 10;
            smallest = min(smallest, dig);
            largest = max(largest, dig);
            num /= 10;
        }

        return largest - smallest;
    }
public:
    int maxDigitRange(vector<int>& nums) {
        int maxDigitRange = 0;
        int currentSum = 0;
        int answer = 0;
        
        for (int& num: nums) {
            int range = getDigitRange(num);
            
            if (range > maxDigitRange) {
                maxDigitRange = range;
                answer = max(answer, currentSum);
                currentSum = 0;
            }

            if (range == maxDigitRange) {
                currentSum += num;
            }
        }

        // if in the end number has highest range then we will consider that
        if (answer != currentSum) {
            answer = currentSum;
        }
        
        return answer;
    }
};