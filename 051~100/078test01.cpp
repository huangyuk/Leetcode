void recu(vector<int>&nums, vector<vector<int>>&sol)
{
    for(int i=0;i<nums.size();i++)
    {
        for(int j=sol.size()-1;j>=0;j--)
        {
            vector<int> temp=sol[j];
            temp.push_back(nums[i]);
            sol.push_back(temp);
        }
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> sol={{}};
    recu(nums,sol);
    return sol;
}
