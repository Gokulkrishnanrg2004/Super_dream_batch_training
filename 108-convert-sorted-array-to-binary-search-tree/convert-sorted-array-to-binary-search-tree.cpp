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
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums,int left,int right)
    {
        int mid = left + (right - left)/2;

        if (left > right) 
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = sortedArrayToBSTHelper(nums,left,mid-1);
        root->right = sortedArrayToBSTHelper(nums,mid+1,right);

        return root;
    } 
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        int n = nums.size();
        return sortedArrayToBSTHelper(nums,0,n-1);    
    }
};