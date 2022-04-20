// https://leetcode.com/problems/binary-search-tree-iterator/

class BSTIterator {
private:
    void inorder(TreeNode* root, vector<int>& inorderList) {
      if (!root) return;
      inorder(root->left, inorderList);
      inorderList.push_back(root->val);
      inorder(root->right, inorderList);
    }  
public:
    // Time: O(N) | Space: O(N)
    vector<int> inorderList;
    int position;
    BSTIterator(TreeNode* root) {
      inorderList = vector<int>();
      position = 0;
      inorder(root, inorderList);
    }
    
    int next() {
      int val = inorderList[position];
      position += 1;
      return val;
    }
    
    bool hasNext() {
      return position < inorderList.size();
    }
};