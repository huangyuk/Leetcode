int largestRectangleArea(vector<int>& heights) {
    int max=0;
    int size=heights.size();
    if(size==0) return 0;
    else if(size==1) return heights[0];
    bool special=1;
    int table[2][size];
    for(int i=0;i<size;i++)
    {
        if(i>0&&heights[i]!=heights[i-1]) special=0;
        table[0][i]=heights[i];
        if(max<1*table[0][i]) max=table[0][i];
    }
    if(special==1) return size*heights[0];

    for(int i=1;i<size;i++)
    {
        for(int j=i;j<size;j++)
        {
            table[i%2][j]=min(table[1-i%2][j-1],table[1-i%2][j]);
            if((i+1)*table[i%2][j]>max) max=(i+1)*table[i%2][j];
        }
    }
    return max;
}
