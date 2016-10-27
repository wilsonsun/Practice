
// Simple DFS, remember to popback()!!!!
void GP_Helper(vector<string> &res, int depth, string cur, int leftCount, int rightCount, const int n) {
    if (depth > n*2) {
        res.push_back(cur);
            return;
    }
    
    if (leftCount < n) {
        cur.push_back('(');
        GP_Helper(res, depth+1, cur, leftCount+1,rightCount, n);
        cur.pop_back();
    }
    
    if (rightCount < leftCount) {
        cur.push_back(')');
        GP_Helper(res, depth+1, cur, leftCount,rightCount+1, n);
        cur.pop_back();
    }
    
    return;
}

vector<string> generateParanthesis(int n) {
    vector<string> res;
    GP_Helper(res, 1, "", 0, 0, n);
    return res;
}
