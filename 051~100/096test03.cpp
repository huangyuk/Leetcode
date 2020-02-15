vector<int> a;
a.push_back(1);
a.push_back(1);
for(int i=2;i<=n;i++)
{
    int sol=0;
    if(i%2==0)
    {
        for(int j=0;j<i/2;j++)
        {
            sol=sol+2*a[j]*a[i-1-j];
        }
        a.push_back(sol);
    }
    else if(i%2==1)
    {
        for(int j=0;j<i/2;j++)
        {
            sol=sol+2*a[j]*a[i-1-j];
        }
        sol=sol+a[i/2]*a[i/2];
        a.push_back(sol);
    }
}
return a[n]; 
