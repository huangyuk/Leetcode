int left(vector<int>& nums, int &target,int begin, int end)
{
    int mid=(begin+end)/2;
    if (mid==begin)
    {
        if(nums[mid]==target) return mid;
        else return end;
    }
    if(nums[mid]==target) return left(nums, target, begin, mid);
    else return left(nums, target, mid, end);
}
int right(vector<int>& nums, int &target,int begin, int end)
{
    int mid=(begin+end)/2;
    if (mid==begin)
    {
        if(nums[mid]==target) return mid;
        else return end;
    }
    if(nums[mid]==target) return right(nums, target, mid, end);
    else return right(nums, target, begin, mid);
}


vector<int> searchRange(vector<int>& nums, int target) {
    int first=0;int last=nums.size();
    vector<int> sol;
    while(first<last)
    {
        int mid=(first+last)/2;
        if(target<nums[mid])
        {
            last=mid;
        }
        else if(target>nums[mid])
        {
            if(mid==first) break;
            first=mid;
        }
        else
        {
            sol.push_back(left(nums,target,0,mid));
            sol.push_back(right(nums,target,mid,nums.size()));
            return sol;
        };
    }
    return {-1,-1};
}
