// https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    // Time: O(N) | Space: O(N)
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        
        int N = nums.size();
        int threshold = N / 3;
        
        vector<int> answer;
        for (int idx = 0; idx < nums.size(); idx++) {
          hashMap[nums[idx]] += 1;
        }
      
        for (auto& map: hashMap) {
          if (map.second > threshold) answer.push_back(map.first);
        }
      
        return answer;
    }
};