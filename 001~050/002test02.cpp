#include<iostream>
#include<string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        else if(s.size()==1) return 1;
        unordered_map<char,int> a;
        int left=0;
        int right=1;
        int max=1;
        a[s[0]]=0;
        while(right<=s.size()-1)
        {
          if(a.count(s[right])&&a.at(s[right])>=left)
          {
            if(right-left>max) max=right-left;
            left=a.at(s[right])+1;
          }
          a[s[right]]=right;
          right=right+1;
        }
        if(right-left>max) max=right-left;
        return max;
    }

int main()
{
  string a="abcdd";
  cout<<lengthOfLongestSubstring(a);
}
