int longestValidParentheses(string s) {
        stack<int> q;
        int j=0;
        int maximum=0;
        bool state=0;
        for(int i=0;i<s.size();i++)
        {
            if(q.empty()&&s[i]==')') state=0;
            else if(q.empty()&&s[i]=='(')
            {
                q.push(s[i]);
                if(state==0)j=i;
                state=1;
            }
            else if(!q.empty()&&s[i]=='(')  {q.push(s[i]);}
            else if(!q.empty()&&s[i]==')')
            {
                q.pop();
                if(q.empty())
                {if((i-j+1)>maximum) maximum=i-j+1;}
            }
        }
        while(!q.empty()) {q.pop();}
        state=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(q.empty()&&s[i]=='(') state=0;
            else if(q.empty()&&s[i]==')')
            {
                q.push(s[i]);
                if(state==0)j=i;
                state=1;
            }
            else if(!q.empty()&&s[i]==')') q.push(s[i]);
            else if(!q.empty()&&s[i]=='(')
            {
                q.pop();
                if(q.empty())
                {if((j-i+1)>maximum) maximum=j-i+1;}
            }
        }
        return maximum;
    }
