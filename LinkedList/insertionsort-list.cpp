// https://leetcode.com/problems/insertion-sort-list

class Solution {
private:
  vector<int> getVectorFromList(ListNode* head) {
    vector<int> nums;
    while (head != NULL) {
      nums.push_back(head->val);
      head = head->next;
    }
    
    return nums;
  }

  void insertionSort(vector<int>& nums) {
    int N = nums.size();
    for (int idx = 1; idx < N; idx++) {
      int current = nums[idx];
      int jdx = idx - 1;

      while (jdx >= 0 && nums[jdx] > current) {
        nums[jdx + 1] = nums[jdx];
        jdx -= 1;
      }

      nums[jdx + 1] = current;
    }
  }
public:
    // Time: O(N * N) | Space: O(N)
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        vector<int> nums = getVectorFromList(head);
        insertionSort(nums);
        ListNode* temp = head;
        int pos = 0;
        while (temp != NULL) {
          temp->val = nums[pos];
          pos += 1;
          temp = temp->next;
        }
      
        return head;
    }
};