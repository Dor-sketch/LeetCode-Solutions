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
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        sumAndCount(root, count);
        return count;
    }

private:
    pair<int, int> sumAndCount(TreeNode* node, int& count) {
        if (!node) return {0, 0};

        auto left = sumAndCount(node->left, count);
        auto right = sumAndCount(node->right, count);
        
        int sum = node->val + left.first + right.first;
        int nodes = 1 + left.second + right.second;

        if (sum / nodes == node->val) {
            count++;
        }

        return {sum, nodes};
    }
};
