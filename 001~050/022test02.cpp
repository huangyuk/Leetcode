string left(int n)
{if(n==0)return "";else return "("+left(n-1);}
string right(int n)
{if(n==0) return "";else return ")"+right(n-1);}
string mid(int n)
{if(n==0) return "";else return "()"+mid(n-1);}
vector<string> helper(int n)
{
    vector<string> help;
    if(n<=1){help.push_back("()");return help;}
    for(int i=1;i<n;i++)
    {help.push_back(left(i)+mid(n-i)+right(i));}
    return help;
}
vector<string> generateParenthesis(int n) {
    vector<string> answer;
    vector<string> temp1;
    vector<string> temp2;
    if(n==0){answer.push_back(""); return answer;}
    else if(n==1){answer.push_back("()");return answer;}
    for(int i=1;i<n;i++)
    {
        temp2=generateParenthesis(n-i);
        temp1=helper(i);
        for(string j:temp2)
        {
            if(i==1) answer.push_back("("+j+")");
            for(string k:temp1)
            {answer.push_back(k+j);}
        }
    }
    return answer;
}
