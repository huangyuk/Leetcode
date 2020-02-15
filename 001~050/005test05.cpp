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
  int i;
  for(int k=0;k<s.size()-1;k++)
  {
    for(i=1;i<s.size()-k;i++)
    {
      if(state==0&&s[k+i]==s[k+i-1])
      {state=1;len=2;}
      else if(k+i>1&&state==0&&s[k+i]!=s[k+i-1]&&s[k+i]==s[k+i-2])
      {state=2;len=3;}
      else if(state==1&&s[k+i]==s[k+i-1]) len++;
      else if(state==1&&s[k+i]!=s[k+i-1]&&(k+i-len-1)<0)
      {state=0;if(len>max){max=len;answer=s.substr(k+i-len,len);} len=0;break;}
      else if(state==1&&s[k+i]!=s[k+i-1]&&s[k+i]==s[k+i-len-1]){state=2;len=len+2;}
      else if(state==1&&s[k+i]!=s[k+i-1]&&s[k+i]!=s[k+i-len-1])
      {state=0;if(len>max){max=len;answer=s.substr(k+i-len,len);} len=0;break;}
      else if(state==2&&(k+i-len-1)<0)
      {state=0;if(len>max){max=len;answer=s.substr(k+i-len,len);} len=0;break;}
      else if(state==2&&s[k+i]==s[k+i-len-1]){len=len+2;}
      else if(state==2&&s[k+i]!=s[k+i-len-1])
      {state=0;if(len>max){max=len;answer=s.substr(k+i-len,len);} len=0;break;}
    }
    if(len>max){max=len;answer=s.substr(s.size()-len,len);}
    if(i==s.size()-k){break;}
  }
  if(max==0) answer=s[0];
  return answer;
}

int main()
{
  string a="babaddtattarrattatddetartrateedredividerb";
  cout<<longestPalindrome(a);
}
