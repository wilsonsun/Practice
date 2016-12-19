void printVec(const vector<vector<int>> &v) {
    int rowSize = (int)v.size();

    
    for (int i = 0; i < rowSize; ++i) {
        int colSize = (int)v[i].size();
        cout << v[i][0];
        for (int j = 1; j < colSize; ++j) {
            cout << ',' << v[i][j];
        }
        cout << endl;
    }
}

int findMaxForm(vector<string>& strs, int m, int n) {
    int len = (int)strs.size();
    
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    
    for (int i = 0; i < len; ++i) {
        int ones = 0; int zeros = 0;
        for (char c:strs[i]) (c == '0')? ++zeros : ++ones;
        
        for (int x = m; x >= zeros; --x) {
            for (int y = n; y >= ones; --y) {
                dp[x][y] = max(dp[x-zeros][y-ones]+1, dp[x][y]);
            }
        }
    }

    
    return dp[m][n];
}

int firstUniqChar(string s) {
    int map[256] = {0};
    
    for (char c : s) {
        int p = (int)c;
        map[p]++;
    }
    
    for (int i = 0; i < s.length(); ++i) {
        if (map[(int)s[i]] == 1)
            return i;
    }
    
    return -1;
}


string longestCommonPrefix(vector<string>& strs) {
    int len = (int)strs.size();
    
    if (len == 0)
        return "";
    if (len == 1)
        return strs[0];
    
    string s = "";
    
    int l = min(strs[0].size(), strs[1].size());
    
    for (int i = 0; i < l; ++i) {
        if (strs[0][i] == strs[1][i])
            s += strs[0][i];
        else
            break;
    }
    
    if (len == 2)
        return s;
    
    for (int i = 2; i < len; ++i) {
        int l = s.size();
        string temp = "";
        for (int j = 0; j < l; ++j) {
            if (s[j] == strs[i][j])
                temp += s[j];
            else {
                s = temp;
                break;
            }
        }
    }
    
    return s;
}

int searchInsert(vector<int>& nums, int target) {
    int len = (int)nums.size();
    
    if (len == 0)
        return 0;
    
    int end = (int)nums.size()-1;
    int start = 0;
    int mid = 0;
    
    while (start+1 < end) {
        mid = start + (end - start)/2;
        if (target == nums[mid])
            return mid;
        if (target > nums[mid])
            start = mid;
        else
            end = mid;
    }
    
    if (target == nums[start])
        return start;
    if (target == nums[end])
        return end;
    if (target > nums[start] && target < nums[end])
        return end;
    if (target < nums[start])
        return start;
    if (target > nums[end])
        return end+1;
    
    return -1;
}

int minimumTotal(vector<vector<int>>& triangle) {
    int len = (int)triangle.size();
    
    if (len == 0)
        return -1;
    
    if (len == 1)
        return triangle[0][0];
    
    vector<vector<int>> dp(len);
    dp[0].push_back(triangle[0][0]);
    
    for (int i = 1; i < len; ++i) {
        int tLen = (int)dp[i-1].size();
        
        dp[i].push_back(dp[i-1][0]+triangle[i][0]);
        for (int j = 1; j < tLen; ++j) {
            dp[i].push_back(min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]);
        }
        
        dp[i].push_back(dp[i-1][tLen-1]+triangle[i][tLen]);
    }
    
    printVec(dp);
    int lastColLen = (int)dp[len-1].size();
    int r = dp[len-1][0];
    for (int i = 1; i < lastColLen; ++i) {
        if (dp[len-1][i] < r)
            r = dp[len-1][i];
    }
    
    return r;
    
}

int improvedMinimumTotal(vector<vector<int>>& triangle) {
    int n = (int)triangle.size();
    
    vector<int> dp = triangle.back();

    
    for (int i = n-2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            
        }
        
    }
    
    return dp[0];
}
