void setZeroes(vector<vector<int>>& matrix) {
    queue<int> q;
    for(int i=0;i<matrix.size();i++)
    {
        bool clean=0;
        for(int j=0;j<matrix[0].size();j++)
        {
            if(matrix[i][j]==0)
            {
                q.push(j);
                clean=1;
            }
        }
        if(clean==1)
           for(int j=0;j<matrix[0].size();j++) matrix[i][j]=0;
    }
    while(!q.empty())
    {
        int j=q.front();
        q.pop();
        for(int i=0;i<matrix.size();i++)
        {
            matrix[i][j]=0;
        }
    }
}
