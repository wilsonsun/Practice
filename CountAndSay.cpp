string CountAndSay(int n) {
    if (n == 0)
        return "";
    if (n == 1)
        return "1";

    string res = "";
    string temp = CountAndSay(n-1);
    
    int count = 0;
    for (int i = 0; i < temp.length(); ++ i) {
        count++;
        if (temp[i] != temp[i+1]) {
            char c = count + '0';
            res += c;
            res += temp[i];
            count=0;
        }
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    //vector<int> A = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
    //int r = jump_Greedy(A);
    //cout << r << endl;

    string r = CountAndSay(5);
    cout << r << endl;
    
    return 0;
}
