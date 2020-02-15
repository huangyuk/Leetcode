void search(vector<vector<char>>& board, string&word, int i, int j, int order, vector<vector<bool>> visited, bool &sol)
{
    if(visited[i][j]) return;
    else if(order==word.size()) {sol=1;return;}
    else visited[i][j]=1;
    char up='0',down='0',left='0',right='0';
    if(i!=0) up=board[i-1][j];
    if(i!=board.size()-1) down=board[i+1][j];
    if(j!=0) left=board[i][j-1];
    if(j!=board[0].size()-1) right=board[i][j+1];
    if(up==word[order])
        search(board,word, i-1, j, order+1,visited,sol);
    if(down==word[order])
        search(board,word, i+1, j, order+1,visited,sol);
    if(left==word[order])
        search(board,word, i, j-1, order+1,visited,sol);
    if(right==word[order])
        search(board,word, i, j+1, order+1,visited,sol);
    return;
}

bool exist(vector<vector<char>>& board, string word) {
    if(word.size()>board.size()*board[0].size()) return false;
    bool sol=false;
    int order=0;
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            if(board[i][j]==word[order])
            {
                vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),0));
                search(board,word, i, j, order+1,visited,sol);
            }
        }
    }
    return sol;
}
