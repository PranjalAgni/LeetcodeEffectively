// https://leetcode.com/contest/weekly-contest-267/problems/reverse-nodes-in-even-length-groups/

class Solution {
   public:
    int countNumNodes(ListNode* head) {
        int count = 0;
        while (head) {
            count += 1;
            head = head->next;
        }

        return count;
    }

    // Time: O(N) | Space: O(1)
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (!head) return head;

        int N = countNumNodes(head);

        int numNodes = 1;
        int groupNum = 1;
        int currentNodeIndex = 0;
        ListNode* runnerNode = head;
        ListNode* prev = NULL;

        while (runnerNode != NULL) {
            bool isEvenNumNodes = ((currentNodeIndex + numNodes - 1) < N) ? (numNodes % 2 == 0) : ((N - currentNodeIndex) % 2 == 0);
            int tempNumNodes = numNodes;
            ListNode* newHead = NULL;
            ListNode* currentHead = runnerNode;
            ListNode* nextNode = NULL;

            while (tempNumNodes-- > 0 && currentHead != NULL) {
                nextNode = currentHead->next;
                if (isEvenNumNodes) {    
                    currentHead->next = newHead;
                    newHead = currentHead;
                    currentHead = nextNode;
                } else {
                    prev = currentHead;
                    currentHead = nextNode;
                }
            }

            if (isEvenNumNodes) {
                if (prev) prev->next = newHead;
                if (runnerNode) runnerNode->next = nextNode;
                prev = runnerNode;
                runnerNode = nextNode;
            } else {
                runnerNode = currentHead;
            }

            currentNodeIndex += numNodes;
            numNodes += 1;
            groupNum += 1;
        }

        return head;
    }
};