bool canPartition(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    int len = (int)nums.size();
    int firstPVal = 0;
    int secondPVal = 0;
    
    for (int i = 0; i < len; ++i) {
        if (i < len/2) {
            firstPVal += nums[i];
        } else {
            secondPVal += nums[i];
        }
    }
    
    if (firstPVal == secondPVal)
        return true;
    
    for (int i = len/2; i < len-1; ++i) {
        firstPVal += nums[i];
        secondPVal -= nums[i];
        if (firstPVal == secondPVal)
            return true;
    }
    
    return false;
}
