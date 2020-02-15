vector<int> a;
a.push_back(1);
a.push_back(1);
for(int i=2;i<=n;i++)
{
    int sol=0;
    for(int j=0;j<i;j++)
    {
        sol=sol+a[j]*a[i-1-j];
    }
    a.push_back(sol);
}
return a[n];
