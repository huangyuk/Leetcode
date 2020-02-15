#include<iostream>
#include<cmath>

using namespace std;

int reverse(int x) {
  int negative=0;
  if(x<0){x=-x;negative=1;}
  long long y=0;
  while(x!=0)
  {
    y=10*y+x%10;
    x=x/10;
    cout<<y<<endl;
  }
  long long a=pow(2,32)-1;
  if(y>a||y<-a) y=0;
  if(negative==1) y=-1*y;
      return y;
    }

int main()
{
   int x=123;
   cout<<reverse(x);
}
