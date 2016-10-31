    vector<int> productExceptSelf(vector<int>& nums) {
        int count = 0;
        int pos = -1;
        int len = (int)nums.size();
        vector<int> res(len, 0);
        
        for (int i = 0; i < len; ++i) {
            if (nums[i] == 0) {
                count++;
                pos = i;
            }
        }
        
        if (count > 1) {
            return res;
        }
        
        if (count == 1) {
            int tempProduct = 1;
            for (int i = 0; i < len; ++i) {
                if (i == pos)
                    continue;
                tempProduct *= nums[i];
            }
            res[pos] = tempProduct;
            return res;
        }
        
        int tempProduct = 1;
        for (int i = 0; i < len; ++i) {
            tempProduct *= nums[i];
        }
        for (int i = 0; i < len; ++i) {
            res[i] = tempProduct/nums[i];
        }
        return res;
    }
