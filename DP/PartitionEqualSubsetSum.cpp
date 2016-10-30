bool canPartition(vector<int>& nums) {
    int len = (int)nums.size();
    int sum = 0;
    
    for (int i = 0; i < len; ++i) {
        sum += nums[i];
    }
    
    if (sum%2 != 0)
        return false;
    
    int target = sum/2;
    vector<bool> dp(target+1, 0);
    dp[0] = true;
    
    for (int i = 0; i < len; ++i) {
        for (int j = target; j >= nums[i]; --j) {
            dp[j] = dp[j] || dp[j-nums[i]];
        }
    }
    
    return dp.back();
}
