void setZeroes(vector<vector<int>>& matrix) {
vector<bool> q(matrix[0].size(),0);
for(int i=0;i<matrix.size();i++)
{
    bool clean=0;
    for(int j=0;j<matrix[0].size();j++)
    {
        if(matrix[i][j]==0)
        {
            q[j]=1;
            clean=1;
        }
    }
    if(clean==1)
       for(int j=0;j<matrix[0].size();j++) matrix[i][j]=0;
}
for(int j=0;j<matrix[0].size();j++)
{
    if(q[j]==1)
    {
         for(int i=0;i<matrix.size();i++)
         {
            matrix[i][j]=0;
         }
    }
}
}
