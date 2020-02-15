#include<iostream>
#include<string>
#include<vector>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> a;
        vector<int> answer;
        int rep[s.size()];
        for(int i=0;i<s.size();i++){rep[i]=-1;}
        int temp=0;
        bool first=0;
        for(int i=0;i<s.size();i++)
        {
            if(!a.count(s[i]))
            {
                a[s[i]]=i;
                if (first==0) answer.push_back(i+1);
            }
            else{
              rep[i]=a.at(s[i]);
              if (first==0) first=1;
              bool index=0;
              for(int j=a.at(s[i]); j<=i;j++)
              {
                if(rep[j]>i) index=1;
              }
              if (index=0) answer.push_back(i-a.at(s[i]));
              if(temp<a.at(s[i])){
                  temp=a.at(s[i]);
              }
              a[s[i]]=i;
            };
        };
        answer.push_back(s.size()-1-temp);
        int max=0;
        for(int i=0;i<answer.size();i++)
        {
          if(answer[i]>max) max=answer[i];
        }
        return max;
    }

int main()
{
  string a="ohomm";
  cout<<lengthOfLongestSubstring(a);
}
