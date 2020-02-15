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
  int max=0;
  string answer;
  int state=0;
  int len=0;
  int lenb=0;
  for(int i=1;i<s.size();i++)
  {
    if(state==0&&s[i]==s[i-1])
    {state=1;len=2;}
    else if(i>1&&state==0&&s[i]!=s[i-1]&&s[i]==s[i-2])
    {state=2;len=3;}
    else if(state==1&&s[i]==s[i-1]) len++;
    else if(state==1&&s[i]!=s[i-1]&&(i-len-1)<0)
    {state=0;if(len>max){max=len;answer=s.substr(i-len,len);} len=0;}
    else if(state==1&&s[i]!=s[i-1]&&s[i]==s[i-len-1]){state=2;len=len+2;}
    else if(state==1&&s[i]!=s[i-1]&&s[i]!=s[i-len-1])
    {state=0;if(len>max){max=len;answer=s.substr(i-len,len);}  len=0;}
    else if(state==2&&s[i]!=s[i-1]&&s[i]==s[i-len-1]){len=len+2;lenb=1;}
    else if(state==2&&s[i]==s[i-1]&&s[i]==s[i-len-1]){len=len+2;lenb++;}
    else if(state==2&&s[i]==s[i-1]&&s[i]!=s[i-len-1])
    {state=1;if(len>max){max=len;answer=s.substr(i-len,len);} len=lenb+1;lenb=0;}
    else if(state==2&&s[i]!=s[i-1]&&s[i]!=s[i-len-1])
    {state=0;if(len>max){max=len;answer=s.substr(i-len,len);} len=0;lenb=0;}
  }
  if(len>max){max=len;answer=s.substr(s.size()-len,len);}
  if(max==0) answer=s[0];
  return answer;
}

int main()
{
  string a="bananas";
  cout<<longestPalindrome(a);
}
