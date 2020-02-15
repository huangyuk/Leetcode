void nextPermutation(vector<int>& nums) {
    int size=nums.size();
    if(size<=1) return;
    int i=size-2;
    while(i>=0)
    {
        if(nums[i]<nums[i+1]) break;
        i--;
    }
    if(i<0){sort(nums.begin(),nums.end());return;}
    int j=size-1;
    while(j>=0)
    {
        if(nums[i]<nums[j]) break;
        j--;
    }
    int temp=nums[i];
    nums[i]=nums[j];
    nums[j]=temp;
    sort(nums.begin()+i+1,nums.end());
    return;
}
