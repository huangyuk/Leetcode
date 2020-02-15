void helper(vector<int>& candidates, int i, int target, vector<int> prev, vector<vector<int>>& sol)
{
    if(candidates[i]>target) return;
    while(target>=candidates[i])
    {
        int j=i-1;
        prev.push_back(candidates[i]);
        target=target-candidates[i];
        if(target==0) {sol.push_back(prev); return;}
        while(j>=0)
        {
            helper(candidates, j, target, prev, sol);
            j--;
        }
    }
    return;
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> sol;
    sort(candidates.begin(), candidates.end());
    int size=candidates.size()-1;
    while(size>=0)
    {
        helper(candidates, size, target, {}, sol);
        size--;
    }
    return sol;
}
