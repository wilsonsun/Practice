int numberOfArithmeticSlices(vector<int>& A) {
    int len = (int)A.size();
    vector<vector<bool>> map(len, vector<bool>(len,0));
    int r = 0;
    
    for (int i = 0; i < len; ++i) {
        for (int j = i+2; j < len; ++j) {
            if (j == i+2) {
                map[i][j] = ((A[i+1]-A[i]) == A[i+2]-A[i+1]);
            } else {
                map[i][j] = (map[i][j-1]&&(A[j]-A[j-1] == A[j-1]-A[j-2]));
            }
            if (map[i][j])
                r++;
        }
    }
    return r;
}
