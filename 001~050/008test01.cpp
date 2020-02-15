#include<iostream>
#include<cmath>
using namespace std;
int myAtoi(string str){
  int sign=1;
  int cont=0;
  unsigned long long y=0;
  for(int i=0;i<str.length();i++)
  {
    if(str[i]==' ')
    {
      if (cont==0) continue;
      else break;
    }
    else if(str[i]>57||str[i]<48)
    {
      if ((str[i]=='-'||str[i]=='+')&&cont==0)
      {
        if(str[i]=='-'){sign=-sign;}
        cont=1;
      }
      else break;
    }
    else if(str[i]<=57&&str[i]>=48)
    {
      y=10*y+int(str[i])-48;
      cont=1;
      cout<<y<<endl;
    }
  }
  y=y*sign;
  long long a=pow(2,31);
  if (y>a-1) return a-1;
  else if(y<-a) return -a;
  else return y;
}


int main()
{
  string a="+-2";
  cout<<myAtoi(a);
  return 0;
}
