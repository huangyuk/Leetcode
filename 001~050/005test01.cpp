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
  int j=0;
  for(j=1;j<s.size();j++)
  {if(s[j]!=s[j-1]) break;}
  if(j==s.size()){return s;}
  int length=0;
  int max=0;
  string answer;
  int state=0;
  for(int k=0;k<s.size();k++)
  {
    state=0;
    j=0;
    for(int i=1;i<s.size()-k;i++)
    {
      if((k+i)>1&&(s[k+i]==s[k+i-2])&&state==0) {state=1;length=3;j=4;}
      else if((s[k+i]==s[k+i-1])&&state==0) {state=1;length=2;j=3;}
      else if(state==1)
      {
        if(k+i-j<k)
        {
          if(length>max)
          {answer=s.substr(k+i-j+1,j-1);max=length;}
          length=0;
          j=0;
          state=0;
          break;
        }
        else if(s[k+i]==s[k+i-j])
        {j=j+2;length=length+2;}
        else
        {
          if(length>max)
          {answer=s.substr(k+i-j+1,j-1);max=length;}
          length=0;
          j=0;
          state=0;
          break;
        }
      }
    }
    if(state==1&&length>max){answer=s.substr(s.size()-j+1,j-1);max=length;break;}
  }
  if(max==0) answer=s[0];
  return answer;
}

int main()
{
  string a="aaabbbbaaa";
  cout<<longestPalindrome(a);
}
