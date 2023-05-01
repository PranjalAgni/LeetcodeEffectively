// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Average Salary Excluding the Minimum and Maximum Salary.
*/
class Solution {
public:
    // Time: O(N) | Space: O(1)
    double average(vector<int>& salary) {
        int minSalary = INT_MAX;
        int maxSalary = INT_MIN;
        int totalSalary = 0;
        for (int& currentSalary: salary) {
          minSalary = min(minSalary, currentSalary);
          maxSalary = max(maxSalary, currentSalary);
          totalSalary += currentSalary;
        }
        
        totalSalary = totalSalary - minSalary - maxSalary;
        double answer = (double) totalSalary / (salary.size() - 2);
        return answer;
    }
};