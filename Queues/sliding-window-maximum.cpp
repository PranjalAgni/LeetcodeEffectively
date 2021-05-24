// Data Structure used: Deque

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;

        int len = nums.size();
        int startWindow = 0;
        vector<int> answer;
        for (int idx = 0; idx < len; idx++) {
            // current element
            int curr = nums[idx];
            // start removing element from back of deque which are less then
            while (!dq.empty() && curr > nums[dq.back()]) {
                dq.pop_back();
            }

            // push the current element in the back (deque is in desc order)
            dq.push_back(idx);

            // check if window size is reached
            // 1. remove the element from the front which are out of window
            // 2. Get the front element which is the answer
            if ((idx - startWindow + 1) == k && !dq.empty()) {
                if (dq.front() < startWindow) {
                    dq.pop_front();
                }
                answer.push_back(nums[dq.front()]);
                startWindow += 1;
            }
        }

        return answer;
    }
};
