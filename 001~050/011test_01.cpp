#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int maxArea(vector<int>& a) {
  int i=0;int j=a.size()-1;
  int max=0;
  while(i<j)
  {
    int temp=(j-i)*min(a[i],a[j]);
    if(temp>max) max=temp;
    if(a[i]<=a[j]) i++;
    else j--;
  }
  return max;

}

int main()
{
  vector<int> a={1,8,6,2,5,4,8,3,7};
  cout<<maxArea(a);

}
