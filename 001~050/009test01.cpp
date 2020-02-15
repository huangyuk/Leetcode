if(x<0) return false;
string a=to_string(x);
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
