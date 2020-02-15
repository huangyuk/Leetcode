#include<iostream>
#include<cmath>
using namespace std;

long long sol=0;
int index=1;
int divide(long long dividend, long long divisor) {
    if((dividend<0&&divisor>0)||(dividend>0&&divisor<0)) index=-1;
    dividend=abs(dividend);
    divisor=abs(divisor);
    while(true)
    {
      if(dividend<divisor)
      {
        if(index==-1) return -sol;
        else return sol;
      }
      else
      {
        sol++;
        long a=pow(2,31);
        if(sol>a) return a-1;

        dividend=dividend-divisor;
      }
    }
}

int main()
{
  cout<<divide(-2147483648,-1);
}
