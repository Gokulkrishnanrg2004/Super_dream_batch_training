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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int,int>inorderIndex;
        for(int i=0;i<inorder.size();i++)
        {
            inorderIndex[inorder[i]] = i;
        }
        return constructTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inorderIndex);
    }
    private:
    TreeNode* constructTree(vector<int>& preorder,int preStart,int preEnd,
                            vector<int>& inorder,int inStart,int inEnd,
                            unordered_map<int,int>& inorderIndex)
    {
        if(preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int rootIndex = inorderIndex[root->val];
        int leftTreeSize = rootIndex - inStart;

        root->left = constructTree(preorder,preStart + 1,preStart + leftTreeSize,inorder,inStart,rootIndex-1,inorderIndex);
        root->right = constructTree(preorder,preStart + leftTreeSize + 1,preEnd,inorder,rootIndex+1,inEnd,inorderIndex);

        return root;
    }
};