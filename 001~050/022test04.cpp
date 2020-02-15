//passed but poor performed;

string right(int n)
{if(n==0) return "";else return ")"+right(n-1);}
vector<string> generateAll(int a,int b)
{
    vector<string> temp;
    vector<string> answer;
    if(a==0) {answer.push_back(right(b));return answer;}
    if(a==b)
    {temp=generateAll(a-1,b);
    for(string i:temp) {answer.push_back("("+i);};
     return answer;
    }
    else
    {
        temp=generateAll(a-1,b);
        for(string i:temp) {answer.push_back("("+i);};
        temp=generateAll(a,b-1);
        for(string i:temp) {answer.push_back(")"+i);}
        return answer;
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> answer=generateAll(n,n);
    return answer;
}
