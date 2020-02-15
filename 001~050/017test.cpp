#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;


vector<string> letterCombinations(string digits) {
  int size=1;
  unordered_map<char,string> a;
  a['2']="abc";a['3']="def";a['4']="ghi";a['5']="jkl";
  a['6']="mno";a['7']="pqrs";a['8']="tuv";a['9']="wxyz";
  for(char i:digits) size=size*a[i].size();
  vector<string> answer(size);
  int cyclesize=1;
  for(int i=0;i<digits.size();i++)
  {
    int index=0;
    size=size/a[digits[i]].size();
    for(int z=0;z<cyclesize;z++)
    {
      for(int j=0;j<a[digits[i]].size();j++)
      {
        for(int k=0;k<(size);k++)
        {
          answer[index]+=a[digits[i]][j];
          index++;
        }
      }
    }
    cyclesize=cyclesize*a[digits[i]].size();
  }
  if(digits=="") answer.clear();
  return answer;
}


int main()
{
  string a="";
  vector<string> v=letterCombinations(a);
  for(string i:v)
  {cout<<i<<" ";}
}
