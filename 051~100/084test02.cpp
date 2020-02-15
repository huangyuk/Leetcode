int largestRectangleArea(vector<int>& heights) {
    set<int> allheights;
    for(int i:heights)
    {allheights.insert(i);}
    int maximum=0;
    int size=heights.size();
    vector<vector<pair<int,int>>> intervals;
    int z=0;
    intervals.push_back({{0,heights.size()}});
    for(auto i=allheights.begin();i!=allheights.end();i++)
    {
        intervals.push_back({});
        for(auto j:intervals[z])
        {
            bool state=0;
            for(int k=j.first;k<j.second;k++)
            {
                int temp1,temp2;
                if(state==0&&heights[k]>=*i&&k==j.second-1)
                {
                    temp2=k+1;temp1=k;
                    intervals[z+1].push_back({temp1,temp2});
                    if((temp2-temp1)*(*i)>maximum) maximum=(temp2-temp1)*(*i);
                }
                else if(state==0&&heights[k]>=*i) {state=1;temp1=k;}
                else if(state==0&&heights[k]<*i) continue;
                else if(state==1&&heights[k]>=*i&&k==j.second-1)
                {
                    state=0;k++;temp2=k;intervals[z+1].push_back({temp1,temp2});
                    if((temp2-temp1)*(*i)>maximum) maximum=(temp2-temp1)*(*i);
                }
                else if(state==1&&heights[k]>=*i) continue;
                else if(state==1&&heights[k]<*i)
                {
                    state=0;temp2=k;intervals[z+1].push_back({temp1,temp2});
                    if((temp2-temp1)*(*i)>maximum) maximum=(temp2-temp1)*(*i);
                }
            }
        }
        z++;
    }
    return maximum;
}
