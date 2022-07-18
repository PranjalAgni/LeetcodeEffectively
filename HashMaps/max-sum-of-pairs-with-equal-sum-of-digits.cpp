// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

class Solution {
private:
    int getSum(int num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        
        return sum;
    }
    unordered_map<int, vector<int>> getSumVsValuesMap(vector<int>& nums) {
        unordered_map<int, vector<int>> hashMap;
        for (int num: nums) {
            int sum = getSum(num);
            hashMap[sum].push_back(num);
        }
        
        return hashMap;
    }
    
    int getLargestPairSum(vector<int>& values) {
        vector<int> elements(2, INT_MIN);
        for (int& value: values) {
            if (value > elements[1]) {
                elements[0] = max(elements[0], elements[1]);
                elements[1] = value;
            } else if (value > elements[0]) {
                elements[1] = max(elements[1], elements[0]);
                elements[0] = value;
            }
        }
        
        return elements[0] + elements[1];
    }
    
public:
    // Time: O(N) | Space: O(N)
    int maximumSum(vector<int>& nums) {
       unordered_map<int, vector<int>> hashMap = getSumVsValuesMap(nums);
       int ans = 0; 
       for (const auto& [key, value]: hashMap) {
            vector<int> values = value;
            int items = values.size();
            if (items >= 2) {
                int currSum = getLargestPairSum(values);
                ans = max(ans, currSum);
            }
       }
        
       return ans == 0 ? -1 : ans; 
    }
};