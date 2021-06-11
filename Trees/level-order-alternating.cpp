/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
vector<int> solve(Tree* root) {
    vector<int> answer;
    if (!root) return answer;

    bool isReverse = true;
    deque<Tree*> q;
    q.push_back(root);

    while (!q.empty()) {
        int nodes = q.size();
        deque<Tree*> dq;

        for (int idx = 0; idx < nodes; idx++) {
            Tree* curr = q.front();
            q.pop_front();
            if (!curr) continue;
            answer.push_back(curr->val);
            if (isReverse) {
                if (curr->left) dq.push_front(curr->left);
                if (curr->right) dq.push_front(curr->right);
            } else {
                if (curr->right) dq.push_front(curr->right);
                if (curr->left) dq.push_front(curr->left);
            }
        }

        q.insert(q.end(), dq.begin(), dq.end());
        isReverse = !isReverse;
    }
    return answer;
}