#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


vector<int> twoSum(vector<int> &nums, int &target)
{
  vector<int> v;
  unordered_map<int,int> a;
  for(int i=0;i<nums.size();i++)
  {
      a[nums[i]]=i+1;
  }
  for(int i=0;i<nums.size();i++)
  {
    if(a.count(target-nums[i]))
    {
      cout<<1;
        v.push_back(i);
        v.push_back(a.at(target-nums[i]));
        break;
    }
  }
  return v;
}



int main()
{
  vector<int> v={2,5,5,11};
  int target=10;
  cout<<twoSum(v,target)[0]<<twoSum(v,target)[1];
/*  std::cout<<v[0]<<" "<<v.size()<<" "<<v.capacity()<<std::endl;
  for(int i=0;i<v.size();i++)
  {std::cout<<v[i]<<std::endl;}
  std::cout<<"size="<<v.size()<<std::endl;

  for(int i=0;i<v.size();i++)
  {
    for(int j=i+1;j<v.size();j++)
    {
      if(v[i]+v[j]==target)std::cout<<i<<","<<j<<std::endl;
    }
  }
  int begin=0;
  int end=v.size();
  for(int i=0;i<v.size();i++)
  std::cout<<b_search(v,v[i],begin,end)<<std::endl;*/

}
