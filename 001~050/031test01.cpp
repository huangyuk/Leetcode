void nextPermutation(vector<int>& nums) {
    bool state=0;
    for(int i=1;i<nums.size();i++)
    {
        if(state==0&&nums[i-1]<=nums[i]) {state=0;}
        else if(state==0&&nums[i-1]>nums[i]) {state=1;}
        else if(state==1&&nums[i-1]>=nums[i]) {state=1;}
        else {state=0;}
    }
    if(state==0)
    {
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                int k=nums[i];
                nums[i]=nums[i-1];
                nums[i-1]=k;
                break;
            }
        }
    }
    if(state==1)
    {
        int i;
        for(i=nums.size()-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                int j;
                for(j=1;j<=nums.size()-i;j++)
                {
                    if(nums[i-1+j]<=nums[i-1])
                    {
                        int k=nums[i-2+j];
                        nums[i-2+j]=nums[i-1];
                        nums[i-1]=k;
                        sort(nums.begin()+i,nums.end());
                        break;
                    }
                }
                if(j==nums.size()-i+1)
                {
                    int k=nums[nums.size()-1];
                    nums[nums.size()-1]=nums[i-1];
                    nums[i-1]=k;
                    sort(nums.begin()+i,nums.end());
                }
                break;
            }
        }
        if(i==0)
        {
            sort(nums.begin(),nums.end());
        }
    }
}
