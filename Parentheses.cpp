bool isValid(string s) {
    vector<char> stk;
    
    if (s[0] == ']' || s[0] == '}' || s[0] == ')')
        return false;
    
    stk.push_back(s[0]);
    
    for (int i = 1; i < (int)s.size(); ++i) {
        if (!stk.empty() && s[i] == ']' && stk.back() == '[') {
            stk.pop_back();
            continue;
        }
        if (!stk.empty() && s[i] == '}' && stk.back() == '{') {
            stk.pop_back();
            continue;
        }
        if (!stk.empty() && s[i] == ')' && stk.back() == '(') {
            stk.pop_back();
            continue;
        }
        stk.push_back(s[i]);
    }
    
    return stk.empty();
}

int longestValidParentheses(string s) {
    int maxLen = 0;
    int start = 0;
    vector<int> stack;
    
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '(') {
            stack.push_back(i);
        } else {
            if (stack.empty())
                start=i+1;
            else {
                stack.pop_back();
                maxLen = max(maxLen, stack.empty()?i-start+1:i-stack.back());
            }
        }
        
    }
    
    return maxLen;
}
