int maxSubArray(vector<int>& nums) {
    int size=nums.size();
    if(size==1) return nums[0];
    int table[2][size];
    int max=-10000;
    for(int i=0;i<size;i++)
    {
        if(nums[i]>max) max=nums[i];
        table[0][i]=nums[i];
    }
    for(int i=1;i<size;i++)
    {
         for(int j=i;j<size;j++)
        {
        table[i%2][j]=table[1-i%2][j-1]+nums[j];
        if(table[i%2][j]>max) max=table[i%2][j];
         }
    }
    return max;
}
