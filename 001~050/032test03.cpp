int maxi=0;
int j=0;
int count=0;
vector<int> a;
for(int i=0;i<s.size();i++)
{
    if(s[i]=='(')
    {
        if(i==0) a.push_back(1);
        else a.push_back(a[i-1]+1);
    }
    else
    {
        if(i==0) a.push_back(-1);
        else a.push_back(a[i-1]-1);
    }
}
bool state=0;j=0;
for(int i=0;i<s.size();i++)
{
    if(state==0&&s[i]=='(')
    {
        j=i;state=1;
    }
    else if(state==0&&s[i]==')') continue;
    else if(state==1&&s[i]==')')
    {
        if(a[i]==a[j]-1)
        {
            if(i-j>maxi) {maxi=i-j;}
        }
        else if(a[i]==a[j]-2){state=0;}
    }
    else if(state==1&&s[i]=='(') continue;
}
j=0;state=0;
for(int i=s.size()-1;i>=0;i--)
{
    if(state==0&&s[i]==')')
    {
        j=i;state=1;
    }
    else if(state==0&&s[i]=='(') continue;
    else if(state==1&&s[i]=='(')
    {
        if(a[i]==a[j]+1)
        {
            if(j-i>maxi) {maxi=j-i;}
            state=0;
        }
    }
    else if(state==1&&s[i]==')') continue;
}
return maxi;
