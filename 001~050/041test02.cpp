int firstMissingPositive(vector<int>& nums) {
    if(nums.empty()) return 1;
    make_heap(nums.begin(), nums.end(), greater<>{});
    while(nums.front()<=0)
    {
        pop_heap(nums.begin(), nums.end(),greater<>{});
        nums.pop_back();
        if(nums.empty()) return 1;
    }
    for(int i=1;;i++)
    {
        if(i!=nums.front())
            return i;
        while(i==nums.front())
        {
            pop_heap(nums.begin(), nums.end(),greater<>{});
            nums.pop_back();
            if(nums.empty()) return i+1;
        }
    }
}
