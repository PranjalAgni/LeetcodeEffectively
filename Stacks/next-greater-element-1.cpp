// https://leetcode.com/problems/next-greater-element-i/
class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashMap;
        vector<int> ans;
        stack<int> st;
        for (int idx = 0; idx < nums2.size(); idx++) {
            while (!st.empty() && st.top() < nums2[idx]) {
                hashMap[st.top()] = nums2[idx];
                st.pop();
            }

            st.push(nums2[idx]);
        }

        for (int elt : nums1) {
            ans.push_back(hashMap.count(elt) ? hashMap[elt] : -1);
        }
        return ans;
    }
};