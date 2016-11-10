void reverseWords(string &s) {
    vector<string> stack;
    int slen = (int)s.size();
    
    string temp = "";
    for (int i = 0; i < slen; ++i) {
        if (s[i] == ' ') {
            if (temp == "")
                continue;
            stack.push_back(temp);
            temp = "";
        } else {
            temp += s[i];
        }
    }
    if (temp != "")
        stack.push_back(temp);
    
    s = "";
    if (!stack.empty()) {
        s += stack.back();
        stack.pop_back();
    }
    
    while (!stack.empty()) {
        s += ' ';
        s += stack.back();
        stack.pop_back();
    }
    
    return;
}
