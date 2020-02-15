#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


vector<int> twoSum(vector<int> &nums, int &target)
{
  unordered_map<int,vector<int>> a;
  for(int i=0;i<nums.size();i++)
  {
    a[nums[i]].push_back(i);
  }
  vector<int> v;
  sort(nums.begin(),nums.end());
  int i=0;int j=nums.size()-1;
  while(i<j)
  {
    if(nums[i]+nums[j]<target) i++;
    else if(nums[i]+nums[j]>target) j--;
    else
    {
      if(nums[i]==nums[j])
      {
        v.push_back(a[nums[i]][0]),v.push_back(a[nums[j]][1]);
      }
      else
      {
        v.push_back(a[nums[i]][0]),v.push_back(a[nums[j]][0]);
      }
      break;
    };
  }
  return v;
}

int main()
{
  vector<int> v={2,5,5,11};
  int target=10;
  cout<<twoSum(v,target)[0]<<twoSum(v,target)[1];
}
