#include<iostream>
#include<vector>
using namespace std;

int helper(vector<int>& nums, int &target, int first, int last)
{
    int mid=(first+last)/2;
    if(nums[mid]>nums[last-1]&&nums[mid]>=nums[first])
    {
        if(target>=nums[mid]||target<nums[first])
            return helper(nums,target,mid,last);
        else
            return helper(nums,target,first,mid);
    }
    else if(nums[mid]<=nums[last-1]&&nums[mid]<nums[first])
    {
        if(target<nums[mid]||target>=nums[first])
            return helper(nums,target,first,mid);
        else
            return helper(nums,target,mid,last);
    }
    else
    {
        while(first<last)
        {
            mid=(first+last)/2;
            cout<<first<<""<<mid<<""<<last<<endl;
            cout<<target<<nums[mid]<<endl;
            if(target<nums[mid])
            {
                last=mid;
            }
            else if(target>nums[mid])
            {
               if(mid==first) break;
               first=mid;
            }
            else return mid;
        }
        return -1;
    }
}
int search(vector<int>& nums, int target) {
    int first=0;int last=nums.size();
    return helper(nums,target,first,last);
}

int main()
{
  vector<int> nums={4,5,6,7,0,1,2};
  cout<<search(nums,0);
  return 0;
}
