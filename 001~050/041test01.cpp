int firstMissingPositive(vector<int>& nums) {
    unordered_set<int> a;
    for(int i:nums) a.insert(i);
    for(int i=1;;i++) if(!a.count(i)) return i;
}
