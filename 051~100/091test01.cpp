int help(string &s,int order)
{
    if(order==s.size()) return 1;
    else if(s[order]=='0') return 0;
    else if(order==s.size()-1) return 1;
    else if(s[order]=='1')
    {
        return help(s,order+1)+help(s,order+2);
    }
    else if(s[order]=='2'&&(s[order+1]=='0'||s[order+1]=='1'||s[order+1]=='2'||s[order+1]=='3'||s[order+1]=='4'||s[order+1]=='5'||s[order+1]=='6'))
    {
        return help(s,order+1)+help(s,order+2);
    }
    else return help(s,order+1);
}
int numDecodings(string s) {
    return help(s,0);
}
