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
    vector<TreeNode*> generateTrees(int start,int end) 
    {
            vector<TreeNode*> result;

    // Base case: if start > end, return null
    if (start > end) {
        result.push_back(nullptr);
        return result;
    }

    // Loop through all values as root
    for (int i = start; i <= end; i++) {
        // Generate all left subtrees with values [start, i-1]
        vector<TreeNode*> leftSubtrees = generateTrees(start, i - 1);
        // Generate all right subtrees with values [i+1, end]
        vector<TreeNode*> rightSubtrees = generateTrees(i + 1, end);

        // Combine left and right subtrees with the current root
        for (auto left : leftSubtrees) {
            for (auto right : rightSubtrees) {
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                result.push_back(root);
            }
        }
    }

    return result;    
    }
    vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return generateTrees(1, n);
}
};