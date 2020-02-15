#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<string>
#include<list>
using namespace std;


string minWindow(string s, string t) {
  queue<int> q;
  unordered_map<char,int> count;
  unordered_set<char> a;
  unordered_map<char,int> a0;
  string answer=s+" ";
  for(char i:t)
  {a.insert(i);a0[i]++;count[i]=0;}
  int j=0;
  int update=0;
  for(j=0;j<s.size();j++)
  {
    if(a0.count(s[j]))
    {
      count[s[j]]++;
      if(count.at(s[j])>=a0.at(s[j])) a.erase(s[j]);
      q.push(j);
      while(a.size()==0)
      {
        if(q.back()-q.front()+1<=answer.size())
        {answer=s.substr(q.front(),q.back()-q.front()+1);update=1;}
        count[s[q.front()]]--;
        if(count[s[q.front()]]<a0[s[q.front()]])
        {a.insert(s[q.front()]);}
        q.pop();
      }
    }
  }
  if(update==0||t.size()>s.size()) return "";
  return answer;
}



int main()
{
    string s="ADOBECODEBANC";
    string t="ABC";
    cout<<minWindow(s,t);
}
