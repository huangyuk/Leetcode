vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> sol;
    unordered_map<string,int> table;
    int j=0;
    for(auto i:strs)
    {
        string temp=i;
        sort(i.begin(),i.end());
        if(table.count(i))
        {
            sol[table[i]].push_back(temp);
        }
        else
        {
            table[i]=j;
            sol.push_back({temp});
            j++;
        }
    }
    return sol;
}
