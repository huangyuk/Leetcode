#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<string>
using namespace std;

string longestPalindrome(string s){
  if(s.size()==0) return "";
  else if(s.size()==1) return s;
  int length=0;
  int max=0;
  string answer;
  int state=0;
  int j=0;
  for(int i=0;i<s.size();i++)
  {
    for(j=1;j<s.size()-i;j++)
    {
      if(j>1&&a[j]==a[j-2])&&state==0)
      {state=2;length=3;}
      else if(a[j]==a[j-1]&&state==0)
      {state=1;length=2;}
      else if(state==1){
        if(s[i]==s[i-j])
        {j=j+2;length=length+2;}
        else
        {
          if(length>max)
          {
            answer=s.substr(i-j+1,j-1);
            max=length;
          }
          length=0;
          j=0;
          state=0;
        }

      }
    }
  }
  if(state==1&&length>max){answer=s.substr(s.size()-j+1,j-1);max=1;}
  if(max==0) answer=s[0];
  return answer;
}

int main()
{
  string a="bb";
  cout<<longestPalindrome(a);
}
