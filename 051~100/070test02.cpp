int combinations(int n,int x)
{
    if(x==0||x==n) return 1;
    if(x>n/2); x=n-x;
    long long temp=1;
    int i=x;
    while(i>0)
    {
        temp=temp*n/(x-i+1);
        n--;
        i--;
    }
    return temp;
}

int climbStairs(int n) {
    int i=0;  //times of step 2;
    int j=n;
    int sum=0;
    while(j>=0)
    {
        sum=sum+combinations(i+j,i);
        i++;
        j=j-2;
    }
    return sum;
}
