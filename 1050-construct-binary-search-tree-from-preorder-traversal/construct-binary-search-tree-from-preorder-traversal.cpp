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
    TreeNode* constructBST(vector<int>& preorder,int& index,int lower,int upper)
    {
        if(index >= preorder.size() || preorder[index] < lower || preorder[index] > upper)
        {
            return nullptr;
        }

        int rootvalue = preorder[index++];
        TreeNode* root = new TreeNode(rootvalue);

        root->left = constructBST(preorder,index,lower,rootvalue);
        root->right = constructBST(preorder,index,rootvalue,upper);

        return root;
    } 
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        int index = 0;
        int lower = INT_MIN,upper = INT_MAX;
        return constructBST(preorder,index,lower,upper);
    }
};