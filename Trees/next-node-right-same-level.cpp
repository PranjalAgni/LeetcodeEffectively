/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
Tree* solve(Tree* tree, int target) {
    queue<Tree*> q;

    q.push(tree);

    bool isNextNode = false;
    while (!q.empty()) {
        int N = q.size();

        for (int idx = 0; idx < N; idx++) {
            Tree* curr = q.front();
            q.pop();

            if (isNextNode) return curr;
            if (curr->val == target && (idx + 1) < N) isNextNode = true;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }

    return NULL;
}