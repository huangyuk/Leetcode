#include<iostream>
#include<string>
#include<vector>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        else if(s.size()==1) return 1;
        unordered_map<char,int> a;
        vector<int> answer;
        int left=0;
        int right=1;
        int temp=1;
        a[s[0]]=0;
        while(right<=s.size()-1)
        {
          cout<<left<<" "<<right<<endl;
          if(!a.count(s[right]))
          {
            a[s[right]]=right;
            temp++;
            right++;
          }
          else
          {
            if(left==1) cout<<a[s[right]]<<" "<<left<<endl;
            if(a.at(s[right])<left||a.at(s[right])==right)
            {
              a[s[right]]=right;
              temp++;
              right++;
            }
            else{
              answer.push_back(temp);
              temp=1;
              left=a.at(s[right])+1;
              if(s[left]==s[right]) a[s[right]]=left;
              right=left+1;
            }
          }
        }
        answer.push_back(temp);
        int max=0;
        for(int i=0;i<answer.size();i++)
        {
          if(answer[i]>max) max=answer[i];
        }
        return max;
    }

int main()
{
  string a="abcaa";
  cout<<lengthOfLongestSubstring(a);
}
