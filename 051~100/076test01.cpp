#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<string>
using namespace std;


string minWindow(string s, string t) {
  queue<int> q;
  unordered_map<char,int> count;
  unordered_set<char> a;
  unordered_set<char> a0;
  bool state=0;
  string answer=s;
  for(char i:t)
  {a.insert(i);a0.insert(i);count[i]=0;}
  int j=0;
  int update=0;
  for(j=0;j<s.size();j++)
  {
    if(state==0&&a0.count(s[j]))
    {
      a.erase(s[j]);
      count[s[j]]++;
      q.push(j);
      state=1;
    }
    else if(state==1&&a0.count(s[j]))  //a.size always >0
    {
      if(a.count(s[j])) a.erase(s[j]);
      count[s[j]]++;
      q.push(j);
      if(a.size()==0)
      {
        while(count.at(s[q.front()])>1)
        {
          count[s[q.front()]]--;
          q.pop();
        }
        if(q.back()-q.front()+1<=answer.size())
        {answer=s.substr(q.front(),q.back()-q.front()+1);update=1;}
        a.insert(s[q.front()]);      //count must be 1,add back to a
        count[s[q.front()]]--;
        q.pop();
      }
    }
  }
  if(update==0) return "";
  return answer;
}



int main()
{
    string s="a";
    string t="a";
    cout<<minWindow(s,t);
}
