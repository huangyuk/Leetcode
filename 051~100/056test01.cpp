vector<vector<int>> sort(vector<vector<int>>& intervals)
{
    map<int,int> sortmap;
    vector<vector<int>> sol;
    for(auto i:intervals)
    {
        if(!sortmap.count(i[0]))
            sortmap[i[0]]=i[1];
        else
            sortmap[i[0]]=max(sortmap.at(i[0]),i[1]);
    }
    for(auto i=sortmap.begin();i!=sortmap.end();i++)
    {
        sol.push_back({i->first,i->second});
    }
    return sol;
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size()<=1) return intervals;
    vector<vector<int>> interval=sort(intervals);
    vector<vector<int>> sol;
    sol.push_back(interval[0]);
    int j=0;
    for(int i=1;i<interval.size();i++)
    {
        if(interval[i][0]<=sol[j][1])
        {
            sol[j][1]=max(interval[i][1],sol[j][1]);
        }
        else
        {
            sol.push_back(interval[i]);
            j++;
        }
    }
    return sol;
}
