bool isValid(string s) {
    stack<char> p;
    for(char i:s)
    {
        if(i=='('||i=='['||i=='{')
        {p.push(i);}
        else if(i==')'||i==']'||i=='}')
        {
            if(i==')') i='(';
            else if(i==']') i='[';
            else i='{';
            if(p.empty()) return false;
            if(p.top()!=i) return false;
            else p.pop();
        }
    }
    if(p.empty()) return true;
    else return false;
}
