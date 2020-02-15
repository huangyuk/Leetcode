string left(int n)
{if(n==0)return "";else return "("+left(n-1);}
string right(int n)
{if(n==0) return "";else return ")"+right(n-1);}

vector<string> generateAll(int a,int b)
{
    vector<string> temp;
    vector<string> answer;
    if(a==0) {answer.push_back(right(b));return answer;}
    else if(b==0) {answer.push_back(left(a));return answer;}
    temp=generateAll(a-1,b);
    for(string i:temp) {answer.push_back("("+i);}
    temp=generateAll(a,b-1);
    for(string i:temp) {answer.push_back(")"+i);}
    return answer;
}
vector<string> generateParenthesis(int n) {
    vector<string> answer=generateAll(n,n);
    int count=0;
    for(int i=0;i<answer.size();i++)
    {
        for(char j:answer[i])
        {
            (j=='(')? count++:count--;
            if(count<0)
            {answer.erase(answer.begin()+i);i--;break;}
        }
        count=0;
    }
    return answer;
}
