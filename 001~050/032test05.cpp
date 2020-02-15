int longestValidParentheses(string s) {
    int count=0;
    int j=0;
    int maximum=0;
    bool state=0;
    for(int i=0;i<s.size();i++)
    {
        if(count==0&&s[i]==')') state=0;
        else if(count==0&&s[i]=='(')
        {
            count++;
            if(state==0)j=i;
            state=1;
        }
        else if(count>0&&s[i]=='(')  count++;
        else if(count>0&&s[i]==')')
        {
            count--;
            if(count==0)
            {if((i-j+1)>maximum) maximum=i-j+1;}
        }
    }
    count=0;
    state=0;
    for(int i=s.size()-1;i>=0;i--)
    {
        if(count==0&&s[i]=='(') state=0;
        else if(count==0&&s[i]==')')
        {
            count++;
            if(state==0)j=i;
            state=1;
        }
        else if(count>0&&s[i]==')') count++;
        else if(count>0&&s[i]=='(')
        {
            count--;
            if(count==0)
            {if((j-i+1)>maximum) maximum=j-i+1;}
        }
    }
    return maximum;
}
