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
    pair<int, TreeNode*> findLCA(TreeNode* root)
    {
        if(!root) return {0, nullptr};

        auto left = findLCA(root->left);
        auto right = findLCA(root->right);

        int leftdep = left.first;
        int rightdep = right.first;

        if(leftdep == rightdep)
        {
            return {leftdep + 1, root};
        }
        else if(leftdep > rightdep)
        {
            return {leftdep + 1, left.second};
        }
        else 
        {
            return {rightdep + 1, right.second};
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        return findLCA(root).second;    
    }
};