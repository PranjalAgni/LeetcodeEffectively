// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/

// Time: O(n log n) | Space: O(n)
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int N = nums.size();
        vector<int> visited(N, 0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (int idx = 0; idx < N; idx++) {
            pq.push(make_pair(nums[idx], idx));
        }
        
        long long answer = 0;
        
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            int pos = p.second;
            pq.pop();
            if (visited[pos]) continue;
            if (pos - 1 >= 0) {
                visited[pos - 1] = 1;
            }
            
            if (pos + 1 < N) {
                visited[pos + 1] = 1;
            }
            
            answer += p.first;
            
        }
        
        return answer;
        
    }
};