void recu(vector<int>&nums, vector<vector<int>>&sol)
{
    int counter=0;
    for(int i=0;i<nums.size();i++)
    {
        for(int j=sol.size()-1;j>=0;j--)
        {
            sol.push_back(sol[j]);
            counter++;
            sol[counter].push_back(nums[i]);
        }
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> sol={{}};
    recu(nums,sol);
    return sol;
}
