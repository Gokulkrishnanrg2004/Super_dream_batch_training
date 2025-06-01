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
    int findmaxpath(TreeNode* root,int& maxi)//passing by refernce is important
    {
        if(!root) return 0;

        int leftpath = max(0,findmaxpath(root->left,maxi));
        int rightpath = max(0,findmaxpath(root->right,maxi));

        maxi = max(maxi, leftpath + rightpath + root->val);

        return max(leftpath,rightpath) + root->val;
    }
    int maxPathSum(TreeNode* root) 
    {
        int maxi = INT_MIN;
        findmaxpath(root,maxi);
        return maxi;
    }
};