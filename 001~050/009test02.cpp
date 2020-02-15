if(x<0) return false;
vector<int> a;
while(x/10>0)
{
       a.push_back(x%10);
       x=x/10;
}
a.push_back(x);
int len=a.size();
int i=0,j=len-1;
if(len%2==1)
{
    while(a[i]==a[j]&&i<j)
    {
        i++;
        j--;
    }
    if(i==j) return true;
    else return false;
}
else
{
    while(a[i]==a[j]&&i<j)
    {
        i++;
        j--;
    }
    if(i==j+1) return true;
    else return false;
}
}
