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
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return false;
        if (head->next == NULL) return true;
        string numStr = "";
        while (head != NULL) {
            char ch = (char)head->val;
            numStr += ch;
            head = head->next;
        }

        string reversedStr = numStr;
        reverse(reversedStr.begin(), reversedStr.end());

        return numStr == reversedStr;
    }
};