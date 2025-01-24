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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        unordered_map<int,int>inorderIndex;
        for(int i=0;i<inorder.size();i++)
        {
            inorderIndex[inorder[i]] = i;
        }
        int postIndex = postorder.size()-1;
        return constructTree(postorder,0,postIndex,inorder,0,inorder.size()-1,inorderIndex);
    }
    private:
    TreeNode* constructTree(vector<int>& postorder,int postStart,int postEnd,
                            vector<int>& inorder,int inStart,int inEnd,
                            unordered_map<int,int>& inorderIndex)
    {
        if(postStart > postEnd || inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(postorder[postEnd]);

        int rootIndex = inorderIndex[root->val];
        int leftTreeSize = rootIndex - inStart;

        root->left = constructTree(postorder,postStart,postStart+leftTreeSize-1,inorder,inStart,rootIndex-1,inorderIndex);
        root->right = constructTree(postorder,postStart+leftTreeSize,postEnd-1,inorder,rootIndex+1,inEnd,inorderIndex); 
        return root;
    }
};