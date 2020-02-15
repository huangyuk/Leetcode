#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<unordered_map>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
  if(nums.size()<3) return {};
  unordered_map<int,int> maps;
  unordered_set<int> sets;
  for(int i: nums)
  {maps[i]++;sets.insert(i);}
  vector<int> a=nums;
  sort(a.begin(),a.end());
  vector<int> b;
  b.push_back(a[0]);
  for(int i=1;i<=a.size()-1;i++)
  {if(a[i]!=a[i-1]) b.push_back(a[i]);}
  vector<vector<int>> sol;
  for(auto i=maps.begin();i!=maps.end();i++)
  {
    if(i->second>=2)
    {
      i->second=i->second-2;
      if(maps.count(-i->first-i->first))
      {
        if(maps.at(-i->first-i->first)>0)
        {
          if(-2*i->first<i->first) sol.push_back({-2*i->first,i->first,i->first});
          else sol.push_back({i->first,i->first,-2*i->first});
        }
      }
      i->second=i->second+2;
    }
  }
  int i=b.size()-1;
  for(;i>=2;i--)
  {
    if(b[i]<0) break;
    sets.erase(b[i]);
    int j=i-1;
    for(;j>=1;j--)
    {
      sets.erase(b[j]);
      if(sets.count(-b[i]-b[j])) sol.push_back({-b[i]-b[j],b[j],b[i]});
      if(b[j]<-b[i]) break;
    }
    for(;j<=i-1;j++)
    {sets.insert(b[j]);}
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
