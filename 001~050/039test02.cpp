void helper(vector<int>& candidates, int i, int target, vector<int> prev, vector<vector<int>>& sol)
{
    if(target==0)
    {sol.push_back(prev); return;}
    else if (i<0) return;
    if(candidates[i]>target) i--;
    if (i<0) return;
    helper(candidates, i-1, target, prev, sol);
    while(target>=candidates[i])
    {
        prev.push_back(candidates[i]);
        target=target-candidates[i];
        helper(candidates, i-1, target, prev, sol);
    }
    return;
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> sol;
    sort(candidates.begin(), candidates.end());
    int size=candidates.size()-1;
    helper(candidates, size, target, {}, sol);
    return sol;
}
