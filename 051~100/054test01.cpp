void addi(vector<int> &sol,vector<vector<int>>& matrix,vector<vector<bool>> & visited,pair<int,int> & a)
{
    visited[a.first][a.second]=1;
    sol.push_back(matrix[a.first][a.second]);
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int x=matrix.size();
    if(x==0) return {};
    int y=matrix[0].size();
    vector<int> sol;
    pair<int,int> a={0,0};
    vector<vector<bool>> visited;
    for(int i=0;i<x;i++)
    {
        visited.push_back({});
        for(int j=0;j<y;j++) visited[i].push_back(0);
    }
    int count=0;
    for(int i=0;;i++)
    {
        if(i>0)
        {if(i%4==0) a.second++; else if(i%4==1) a.first++; else if(i%4==2) a.second--; else a.first--;}
        while(true)
        {
            addi(sol,matrix,visited,a);count++;
            if(i%4==0)
            {
                if(a.second==y-1) break;
                else if(visited[a.first][a.second+1]==1) break;
                else a.second++;
            }
            else if(i%4==1)
            {
                if(a.first==x-1) break;
                else if(visited[a.first+1][a.second]==1) break;
                else a.first++;
            }
            else if(i%4==2)
            {
                if(a.second==0) break;
                else if(visited[a.first][a.second-1]==1) break;
                else a.second--;
            }
            else if(i%4==3)
            {
                if(a.first==0) break;
                else if(visited[a.first-1][a.second]==1) break;
                else a.first--;
            }
        }
        if(count==x*y) break;
    }
    return sol;
}
