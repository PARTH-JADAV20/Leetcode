/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        int count = 0;
        preOrder(p, q, count);
        return count == 0;
    }
    void preOrder(TreeNode* root1, TreeNode* root2, int& count) {
    if (root1 == nullptr && root2 == nullptr) return;
    if (root1 == nullptr || root2 == nullptr) {
        count++;
        return;
    }
    if (root1->val != root2->val){
        count ++;
    }
    preOrder(root1->left, root2->left, count);
    preOrder(root1->right, root2->right, count);
    }
};