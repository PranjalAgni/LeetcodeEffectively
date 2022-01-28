class Solution {
private:
  void inorder(TreeNode* root, vector<int>& elements) {
    if (!root) return;
    inorder(root->left, elements);
    elements.push_back(root->val);
    inorder(root->right, elements);
  }
  vector<int> merge(vector<int>& elements1, vector<int>& elements2) {
    int N = elements1.size();
    int M = elements2.size();
    int start1 = 0;
    int start2 = 0;
    vector<int> answer;
    
    while (start1 < N || start2 < M) {
      if (start1 < N && start2 < M) {
        if (elements1[start1] < elements2[start2]) {
          answer.push_back(elements1[start1]);
          start1 += 1;
        } else {
          answer.push_back(elements2[start2]);
          start2 += 1;
        }
      } else if (start1 < N) {
        answer.push_back(elements1[start1]);
        start1 += 1;
      } else {
        answer.push_back(elements2[start2]);
        start2 += 1;
      }
    }
    
    return answer;
  }
public:
    // Time: O(N + M) | Space: O(N + M)
    // N = number of nodes in root1
    // M = number of nodes in root2
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
      vector<int> elements1, elements2;
      inorder(root1, elements1);
      inorder(root2, elements2);
      return merge(elements1, elements2);
    }
};