bool canJump(vector<int>& nums) {
    int size=nums.size();
    if(size<=1) return true;
    bool state=1;
    int lastzero=0;
    for(int j=size-2;j>=0;j--)
    {
        if(state==1&&nums[j]==0)
        {state=0;lastzero=j;}
        else if(state==0&&(j+nums[j])>lastzero) state=1;
    }
    if(state==0) return false;
    else return true;
}
