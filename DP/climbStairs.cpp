    int foo(int n, vector<int> &map) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        if (map[n])
            return map[n];
        map[n] = foo(n-1, map)+foo(n-2, map);
        return map[n];
    }
    
    int climbStairs(int n) {
        vector<int> map(n+1,0);
        return foo(n, map);
        
    }
