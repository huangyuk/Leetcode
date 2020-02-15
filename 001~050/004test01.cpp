#include<iostream>
#include<vector>
using namespace std;


int bisearch(vector<int> &nums,double a){
  int p2=nums.size();
  if (a==nums[0]) return 0;
  int p1=0;
  int p;
  while(true)
  {
    p=(p2+p1)/2;
    if(p==0) p=1;
    if (a==nums[p]) return p;
    else if (a<nums[p]) p2=p;
    else p1=p;
    if (p2==p1+1) break;
  }
  return p1;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1=nums1.size();
        int s2=nums2.size();
        int p1,p2;
        if(s1==1&&s2==1){return double(nums1[0]+nums2[0])/2;}
        else if (s1==1)
        {
          int special=bisearch(nums2,nums1[0]);
          if (special<s2/2-1)
          {
            if(s2%2==0) return nums2[s2/2];
            else return double((nums2[s2/2-1]+nums2[s2/2]))/2;
          }
          else if(special==s2/2-1)
          {
            if(s2%2==0) return nums1[0];
            else return double((nums1[0]+nums2[special+1]))/2;
          }
          else
          {
            if(s2%2==0) return nums2[s2/2];
            else return double((nums2[s2/2+1]+nums2[s2/2]))/2;
          }
        }
        else if(s2==1)
        {return findMedianSortedArrays(nums2,nums1);}
        else{
           p1=s1/2-1;
           p2=(s1+s2)/2-p1-2;
         }
        cout<<p1<<" "<<p2<<endl;
        if(s1==0)
        {
          if(s2%2==1) return nums2[s2/2];
          else return (nums2[s2/2-1]+nums2[s2/2])/2;
        }
        else if(s2==0)
        {
          if(s1%2==1) return nums1[s1/2];
          else return (nums1[s1/2-1]+nums1[s1/2+1])/2;
        }
        cout<<s1+s2<<endl;
        while(true)
        {
          int temp=min(s2-p2,s1-p1);
          temp=temp/2;
          if(temp==0) temp=1;
          if(nums1[p1+1]>=nums2[p2]&&nums2[p2+1]>=nums1[p1]) break;
          else if(nums1[p1+1]<nums2[p2])
          {
            p1=p1+temp;
            p2=p2-temp;
          }
          else
          {
            p2=p2+temp;
            p1=p1-temp;
          }
        }
        cout<<p1<<" "<<p2<<endl;
        int s=s1+s2;
        if(p1==-1)
        {
          if (s%2==1) return nums2[s/2];
          else if (p2==s2-1){return double(nums1[0]+nums2[p2])/2;}
          else return double(nums2[s/2-1]+nums2[s/2])/2;
        }
        else if (p2==-1)
        {
          if (s%2==1) return nums1[s/2];
          else if(p1==s1-1)
          {return double(nums2[0]+nums1[p1])/2;}
          else
          return double(nums1[s/2-1]+nums1[s/2])/2;
        }
        else if ((s1+s2)%2==1) return min(nums1[p1+1],nums2[p2+1]);
        else return (double(max(nums1[p1],nums2[p2]))+double(min(nums1[p1+1],nums2[p2+1])))/2;
//        cout<<nums1[0]<<nums1.size();
    }

int main()
{
  vector<int> a={1,2,3};
  vector<int> b={3,4,5,6,7};
//  double a0=b[0];
//  cout<<bisearch(a,a0);
  cout<<findMedianSortedArrays(a, b);
}
