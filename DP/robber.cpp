int rob(vector<int>& nums) {
    int len = (int)nums.size();
    if (len == 0)
        return 0;
    if (len == 1)
        return nums[0];
    if (len == 2)
        return max(nums[0], nums[1]);
    vector<int> map (len, 0);
    map[0] = nums[0];
    map[1] = max(nums[0], nums[1]);
    
    for (int i = 2; i < len; ++i) {
        map[i] = max(map[i-2]+nums[i], map[i-1]);
    }
    
    return map[len-1];
}

int rob_helper(vector<int> &nums, int left, int right) {
    if (right - left == 0)
        return nums[left];
    if (right - left == 1)
        return max(nums[left], nums[right]);
    
    vector<int> map(right+1, 0);
    map[left] = nums[left];
    map[left+1] = max(nums[left], nums[left+1]);
    
    for (int i = left+2; i < right; ++i) {
        map[i] = max(map[i-2]+nums[i], map[i-1]);
    }
    
    return map[right-1];
}

int rob_v2(vector<int> &nums) {
    int len = (int)nums.size();
    if (len == 0)
        return 0;
    if (len == 1)
        return nums[0];
    if (len == 2)
        return max(nums[0], nums[1]);
    return max(rob_helper(nums, 0, (int)nums.size()-1), rob_helper(nums, 1, (int)nums.size()));
}
