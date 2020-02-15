vector<string> table(int n)
{
    vector<vector<vector<string>>> answer;
    for(int i=0;i<=n;i++)
    {
        answer.push_back({});
        for(int j=0;j<=n-i;j++)
        {
            answer[i].push_back({});
            if(i==0)
            {
                if(j==0) {answer[i][j].push_back("");}
                else
                {
                    for(string k:answer[i][j-1])
                    {answer[i][j].push_back(")"+k);}
                }
            }
            else if(j==0)
            {
                   for(string k:answer[i-1][j+1])
                   {answer[i][j].push_back("("+k);}
            }
            else
            {
                for(string k:answer[i-1][j+1])
                {answer[i][j].push_back("("+k);}
                for(string k:answer[i][j-1])
                {answer[i][j].push_back(")"+k);}
            }
        }
    }
    return answer[n][0];
}
vector<string> generateParenthesis(int n) {
    vector<string> answer;
    if(n==0) {answer.push_back("");return answer;}
    answer=table(n);
    return answer;
}
