void reverseWords(string &s) {
    vector<string> stack;
    int slen = (int)s.size();
    if (s == "")
        return;
    
    string temp = "";
    for (int i = 0; i < slen; ++i) {
        if (s[i] == ' ') {
            stack.push_back(temp);
            temp = "";
        } else {
            temp += s[i];
        }
    }
    
    stack.push_back(temp);
    
    s = "";
    while (!stack.empty()) {
        s += stack.back();
        stack.pop_back();
    }
    
    return;
}
