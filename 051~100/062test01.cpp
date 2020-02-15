#include<iostream>
using namespace std;
long long factorial(int x, int count)
{
    if(x==0) return 1;
    else if(count==1) return x;
    else return x*factorial(x-1,count-1);
}
int uniquePaths(int m, int n) {
    if(m==1||n==1) return 1;
    if(m<n)
        return factorial(m+n-2,m-1)/factorial(m-1,m-1);
    else
        return factorial(m+n-2,n-1)/factorial(n-1,n-1);
}

int main()
{
  cout<<uniquePaths(10,10);
}
