/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp = head;
        int len = 0;
        while (temp != NULL) {
            temp = temp->next;
            len += 1;
        }

        vector<int> answer(len, 0);
        temp = head;
        stack<pair<int, int>> st;
        int idx = 0;
        while (temp != NULL) {
            while (!st.empty() && temp->val > st.top().second) {
                answer[st.top().first] = temp->val;
                st.pop();
            }

            st.push({idx, temp->val});
            idx += 1;
            temp = temp->next;
        }

        return answer;
    }
};