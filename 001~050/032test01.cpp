int max=0;
int i=0;
int j=0;
int count=0;
for(int k=0;k<s.size();k++)
{
j=k;i=k;count=0;
j=k;i=k;count=0;
while(i<s.size())
{
    if(s[i]=='(')
        count++;
    else
        count--;
    if(count<=0)
    {
        if(count==0&&i-j+1>max) {max=i-j+1;}
        i++;
        if(count<0)
        {j=i;
         if(i<s.size()) count=0;
        }
    }
    else
    {i++;}
}
if(count==0)
{if(i-j>max) max=i-j;}
}
return max;
