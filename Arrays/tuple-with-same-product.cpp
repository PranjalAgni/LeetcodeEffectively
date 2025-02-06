// https://leetcode.com/problems/tuple-with-same-product/

// Time: O(N^2) | Space: O(N)
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> hashMap;
        int res = 0;

        for(int i = 0 ; i < n ; ++i) {
            for(int j = 0 ; j < i ; ++j){
                int prod = nums[i] * nums[j];
                hashMap[prod] += 1;
                if (hashMap[prod] > 1) {
                    res += 8 * (hashMap[prod] - 1);
                }
            }
        }

        return res;
    }
};