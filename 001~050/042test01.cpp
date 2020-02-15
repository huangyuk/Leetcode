int count(vector<int>& height,int i,int j)
{
    int depth=min(height[i],height[j]);
    int sum=0;
    while(i<j)
    {
        if(depth-height[i]>0) sum=sum+depth-height[i];
        i++;
    }
    return sum;
}

int trap(vector<int>& height) {
    if(height.size()==0||height.size()==1) return 0;
    int i=0; int j=1;
    int sum=0;
    int state=0;
    int size=height.size();
    map<int,vector<int>> ranks;
    vector<int> peak;
    while(j<size)
    {
        if(state==0&&(height[j-1]>height[j]))
        {
            state=1;peak.push_back(j-1);
        }
        else if(state==1&&(height[j-1]<height[j])) state=0;
        if(state==0&&j==size-1) peak.push_back(j);
        j++;
    }
    for(int i:peak)
    {ranks[height[i]].push_back(i);}
    j=peak.size();
    if(j==1) return 0;
    map<int,int> rank_to_position;
    for(auto i:ranks)
    {
        for(int k:i.second)
        {
            rank_to_position[j]=k;
            j--;
        }
    }
    int upper;int lower;
    if(rank_to_position.at(1)<rank_to_position.at(2)){
        lower=rank_to_position.at(1);upper=rank_to_position.at(2);}
    else
    {lower=rank_to_position.at(2);upper=rank_to_position.at(1);}
    sum=sum+count(height,lower,upper);
    for(auto i=rank_to_position.begin();i!=rank_to_position.end();i++)
    {
        if(i->second>upper)
        {
            sum=sum+count(height,upper,i->second);
            upper=i->second;
        }
        else if(i->second<lower)
        {
            sum=sum+count(height,i->second,lower);
            lower=i->second;
        }
    }
    return sum;
    }
