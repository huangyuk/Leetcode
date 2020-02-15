void search(vector<vector<char>>& board, string&word, int i, int j, int order, char temp, bool &sol)
{
    if(order==word.size()) {sol=1;return;}
    char up='0',down='0',left='0',right='0';
    if(i!=0) up=board[i-1][j];
    if(i!=board.size()-1) down=board[i+1][j];
    if(j!=0) left=board[i][j-1];
    if(j!=board[0].size()-1) right=board[i][j+1];
    if(up==word[order])
    {   temp=board[i-1][j];board[i-1][j]='1';
        search(board,word, i-1, j, order+1,temp,sol);
        board[i-1][j]=temp;
    };
    if(down==word[order])
    {   temp=board[i+1][j];board[i+1][j]='1';
        search(board,word, i+1, j, order+1,temp,sol);
        board[i+1][j]=temp;
    }
    if(left==word[order])
    {   temp=board[i][j-1];board[i][j-1]='1';
        search(board,word, i, j-1, order+1,temp,sol);
        board[i][j-1]=temp;
    }
    if(right==word[order])
    {   temp=board[i][j+1];board[i][j+1]='1';
        search(board,word, i, j+1, order+1,temp,sol);
        board[i][j+1]=temp;
    }
    return;
}

bool exist(vector<vector<char>>& board, string word) {
    if(word.size()>board.size()*board[0].size()) return false;
    if(word.size()>400) return true;
    bool sol=false;
    int order=0;
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            if(board[i][j]==word[order])
            {
                char temp=board[i][j];
                board[i][j]='1';
                search(board,word, i, j, order+1,temp,sol);
                board[i][j]=temp;
            }
        }
    }
    return sol;
}
