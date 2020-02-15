#include<iostream>
#include<string>
#include<vector>
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
          cout<<left<<" "<<right<<endl;
          if(!a.count(s[right]))
          {
            a[s[right]]=right;
            right++;
          }
          else
          {
            if(left==1) cout<<a[s[right]]<<" "<<left<<endl;
            if(a.at(s[right])<left)
            {
              a[s[right]]=right;
              right++;
            }
            else{
              if(right-left>max) max=right-left;
              left=a.at(s[right])+1;
              a[s[right]]=right;
              right=right+1;
            }
          }
        }
        if(right-left>max) max=right-left;
        return max;
    }

int main()
{
  string a="ab";
  cout<<lengthOfLongestSubstring(a);
}
