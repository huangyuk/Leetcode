#include<iostream>
#include<cmath>
using namespace std;


int divide(int dividend, int divisor) {
  bool negative=0;
  int sol=0;
  if(dividend<=-2147483648&&divisor==-1) return 2147483647;
  else if(dividend<=-2147483648&&divisor==1) return -2147483648;
  else if(dividend>=2147483648&&divisor==-1) return -2147483648;
  else if(dividend>=2147483648&&divisor==1) return 2147483647;
  if(dividend<0&&divisor>0){negative=1;dividend=-dividend;}
  else if(dividend>0&&divisor<0){negative=1;divisor=-divisor;}
  else if(dividend<0&&divisor<0){dividend=-dividend;divisor=-divisor;}
  if(divisor==1&&negative==1) return -dividend;
  else if(divisor==1&&negative==0) return dividend;
  else if (dividend<divisor) return 0;
  int i=0;
  while(dividend>(divisor<<i))
  {i++;}
  while(i!=-1)
  {
      while(dividend>=(divisor<<i))
      {
          dividend=dividend-(divisor<<i);
          sol=sol+(1<<i);
      }
      i--;
  }
  if(negative==1) return -sol;
  else return sol;
    }
}

int main()
{
  cout<<divide(104,3);
}
