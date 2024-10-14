// https://leetcode.com/problems/maximal-score-after-applying-k-operations/

// TC: O(n + klogn) | Space: O(n)
// priority queue initialization takes O(N)
// we pull k times from pq
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long answer = 0;
        for (int& num: nums) {
            pq.push(num);
        }
        
        while (k-- > 0) {
            int val = pq.top();
            answer += val;
            pq.pop();
            pq.push(ceil((val * 1.0) / 3.0));
        }
        
        return answer;
    }
};