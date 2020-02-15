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
  vector<int> a=nums;
  sort(a.begin(),a.end());
  vector<vector<int>> sol;
  int i=0;
  while(i<=a.size()-2)
  {
    int j=i+1;int k=a.size()-1;
    while(j<k)
    {
      if(a[i]+a[j]+a[k]<0)
      {
        while(a[j]==a[j+1]&&j<a.size()-2){j++;}
        j++;
      }
      else if(a[i]+a[j]+a[k]>0)
      {
        while(a[k]==a[k-1]&&k>1){k--;}
        k--;
      }
      else
      {
        sol.push_back({a[i],a[j],a[k]});
        while(a[j]==a[j+1]&&j<a.size()-2){j++;}
        while(a[k]==a[k-1]&&k>1){k--;}
        j++;k--;
      }
    }
    while(a[i]==a[i+1]&&i<=a.size()-2){i++;}
    i++;
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
  vector<int> a={0,0,0};
  vector<vector<int>> b=threeSum(a);
  for(vector<int> i :b)
  {
    for(int j:i){
      cout<<j<<" ";
    }
    cout<<endl;
  }
}
