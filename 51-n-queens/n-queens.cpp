class Solution 
{
    public:
    bool issafe(int n,int row,int col,vector<string>&board)
    {
        for(int i=0;i<row;i++)
        {
            if(board[i][col] == 'Q') return false;
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
        {
            if(board[i][j] == 'Q') return false;
        }
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
        {
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    void solve(int row,int n,vector<string>&board,vector<vector<string>>&solution)
    {
        if(row == n)
        {
            solution.push_back(board);
            return;
        }
        for(int col=0;col<n;col++)
        {
            if(issafe(n,row,col,board))
            {
                board[row][col] = 'Q';
                solve(row+1,n,board,solution);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>solution;
        solve(0,n,board,solution);

        return solution;
    }
};