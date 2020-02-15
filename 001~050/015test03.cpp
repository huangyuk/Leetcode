#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<unordered_set>
#include<unordered_map>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
  if(nums.size()<3) return {};
  unordered_map<int,int> maps;
  for(int i: nums)
  {maps[i]++;}
  if(maps.size()==1&&maps.count(0)){return {{0,0,0}};}
  vector<int> a=nums;
  sort(a.begin(),a.end());
  bool break_tag=0;
  int i=a.size()-1;
  vector<vector<int>> sol;
  for(;i>=2;i--)
  {
    if(a[i]<0) break;
    maps[a[i]]--;
    for(int j=i-1;j>=0;j--)
    {
      maps[a[j]]--;
      if(maps.count(-a[i]-a[j]))
      {
        if(maps.at(-a[i]-a[j])>0)
        {
          for(int l=sol.size()-1;l>=0;l--)
          {
            if(sol[l][2]>a[i]) break;
            if(sol[l][1]>a[j]&&sol[l][2]==a[i]) break;
            if(sol[l][0]==(-a[i]-a[j])&&sol[l][1]==a[j]&&sol[l][2]==a[i]) {break_tag=1; break;}
          }
          if(!break_tag) sol.push_back({-a[i]-a[j],a[j],a[i]});
          break_tag=0;
        }
      }
    }
    for(int j=i-1;j>=0;j--)
    {maps[a[j]]++;}
    a.pop_back();
  }
  return sol;
}

/*
break_tag=0;
for(int l=sol.size()-1;l>=0;l--)
{
  if(a[i]==4) {cout<<-a[i]-a[j]<<" "<<a[j]<<" "<<a[i]<<endl;
  for(vector<int> i :sol)
  {
    for(int j:i){
      cout<<j<<" ";
    }
  }cout<<endl;
}

*/

int main()
{
  vector<int> a={-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
  vector<vector<int>> b=threeSum(a);
  for(vector<int> i :b)
  {
    for(int j:i){
      cout<<j<<" ";
    }
    cout<<endl;
  }
}
