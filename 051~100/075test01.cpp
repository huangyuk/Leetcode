#include<iostream>
#include<vector>
using namespace std;

void quicksort(vector<int>&nums, int begin, int end, int &temp)
{
    if(begin>=end-1) return;
    int i=begin+1;int j=begin+1;
    while(j<end)
    {
        if(nums[j]>nums[begin])
        {j++;}
        else
        {
            temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;j++;
        }
    }
    temp=nums[i-1];
    nums[i-1]=nums[begin];
    nums[begin]=temp;
    quicksort(nums,begin,i-1,temp);
    quicksort(nums,i,end,temp);
}

int main()
{
  int temp=0;
  vector<int> a={2,1,5,3};
  quicksort(a,0,a.size(),temp);
  cout<<a[0];
}
