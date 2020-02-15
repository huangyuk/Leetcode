string helper(int n)
{
    if(n==0) return "";
    else return "("+helper(n-1)+")";
}
vector<string> generateParenthesis(int n) {
    vector<string> answer;
    vector<string> temp;
    for(int i=1;i<n;i++)
    {
        temp=generateParenthesis(n-i);
        for(string j:temp)
        {
            answer.push_back(helper(i)+j);
        }
    }
    answer.push_back(helper(n));
    return answer;
}
