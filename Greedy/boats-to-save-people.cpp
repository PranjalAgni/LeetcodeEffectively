// https://leetcode.com/problems/boats-to-save-people/

class Solution {
public:
    // Time: O(N*logN) | Space: O(1)
    int numRescueBoats(vector<int>& people, int limit) {
        // sort people in descending order
        sort(people.rbegin(), people.rend());
        int N = people.size();  
        int left = 0;
        int right = N - 1;
        
        // 1. Try to pair heaviest person with lightest
        // 2. If weight exceeds the limit then heaviest person will go alone
        // 3. left stores our answer as it contains the count till how many people we can fit in boat 
        while (left <= right) {
          if (people[left] + people[right] <= limit) right -= 1;
          left += 1;
        }
      
        return left;
    }
};