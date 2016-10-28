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
