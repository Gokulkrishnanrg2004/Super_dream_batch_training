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
    void bfs(TreeNode* root,unordered_map<int,list<int>>&adjlist)
    {
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if(node->left)
            {
                q.push(node->left);
                adjlist[node->val].push_back(node->left->val);
                adjlist[node->left->val].push_back(node->val);
            }
            if(node->right)
            {
                q.push(node->right);
                adjlist[node->val].push_back(node->right->val);
                adjlist[node->right->val].push_back(node->val);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) 
    {
        if(root == nullptr) return 0;

        unordered_map<int,list<int>>adjlist;
        bfs(root,adjlist);

        unordered_map<int,bool>visited;

        queue<pair<int,int>>q;
        q.push({start,0});
        visited[start] = true;

        int totaltime = 0;

        while(!q.empty())
        {
            auto it = q.front();
            int node = it.first;
            int t = it.second;
            q.pop();

            totaltime = max(totaltime,t);
            for(auto neighbour : adjlist[node])
            {
                if(!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push({neighbour,t+1});
                }
            }
        }
        return totaltime;
    }
};