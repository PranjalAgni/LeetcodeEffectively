// Calculate minimum number of nodes in each segment (len / k)
// Extra nodes required in how many segment len % k
// totalNumNodes = minNumNode + (extraNode > 0 ? 1 : 0)
// Then simple pointer game

class Solution {
   public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> answer(k);
        int len = 0;
        ListNode* temp = root;

        while (temp != NULL) {
            temp = temp->next;
            len += 1;
        }

        int minNodes = len / k;
        int extraNodes = len % k;

        int idx = 0;
        bool isHead = true;
        while (root != NULL && idx < k) {
            int limit = minNodes + (extraNodes > 0 ? 1 : 0);
            extraNodes -= 1;

            ListNode* rootPrev = NULL;
            while (root != NULL && limit-- > 0) {
                if (isHead) answer[idx] = root;
                rootPrev = root;
                root = root->next;
                isHead = false;
            }

            rootPrev->next = NULL;
            isHead = true;
            idx += 1;
        }

        return answer;
    }
};