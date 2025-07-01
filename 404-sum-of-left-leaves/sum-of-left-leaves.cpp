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
class Solution 
{
    public:
    void check(TreeNode* root,int& sum)
    {
        if(!root) return;

        if(root->left)
        {
            if(root->left->left == nullptr && root->left->right == nullptr)
            {
                sum += root->left->val;
            }
        }    
        check(root->left,sum);        
        check(root->right,sum);        
    }
    int sumOfLeftLeaves(TreeNode* root) 
    {
        int sum = 0;
        check(root,sum);
        return sum;
    }
};