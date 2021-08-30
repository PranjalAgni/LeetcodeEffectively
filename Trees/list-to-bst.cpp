/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

Tree* constructBST(vector<int>& nums, int start, int end) {
    if (start >= end) return NULL;
    int mid = start + floor((end - start) / 2);
    Tree* node = new Tree(nums[mid]);
    node->left = constructBST(nums, start, mid);
    node->right = constructBST(nums, mid + 1, end);
    return node;
}

Tree* solve(vector<int>& nums) {
    int N = nums.size();
    if (N == 0) return NULL;
    return constructBST(nums, 0, N);
}