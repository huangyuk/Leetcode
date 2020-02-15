int ma=0;
int i=0;
int j=0;
int count=0;
while(i<s.size())
{if(s[i]=='(') count++;
 else count--;
 if(count<=0)
 {
    if(count==0&&i-j+1>ma) {ma=i-j+1;}
    i++;
    if(count<0)
    {j=i;
     if(i<s.size()) count=0;
         }
    }
    else i++;
 }
return max(ma, longestValidParentheses(s.substr(1,s.size()-1)));
}
