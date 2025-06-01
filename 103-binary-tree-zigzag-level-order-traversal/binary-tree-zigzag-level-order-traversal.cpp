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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>>result;
        if(!root)
        {
            return result;
        }
        queue<TreeNode*>q;
        q.push(root);
        int k = 0;
        while(!q.empty())
        {
            int level = q.size();
            vector<int>arr;
            for(int i=0;i<level;i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                arr.push_back(curr->val);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(k%2 != 0)
            {
                reverse(arr.begin(),arr.end());
            }
            result.push_back(arr);
            k++;
        }
        return result;
    }
};