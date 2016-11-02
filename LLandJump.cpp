struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* runnerHead = head;
    ListNode* runnerTail = head;
    for (int i = 0; i < n; ++i)
        runnerTail = runnerTail->next;
    
    if (runnerTail == NULL)
        return head->next;
    
    while (runnerHead->next != NULL && runnerTail->next != NULL) {
        runnerHead = runnerHead->next;
        runnerTail = runnerTail->next;
    }
    
    ListNode* temp = runnerHead->next;
    runnerHead->next = runnerHead->next->next;

    free(temp);
    return head;
}

void jump_Helper(vector<int> &nums, int steps, int index,  vector<int> &res) {
    int len = (int)nums.size();
    if (index >= len-1) {
        res.push_back(steps);
        return;
    }
    
    for (int i = 1; i <= nums[index]; i++) {
        jump_Helper(nums, steps+1, index+i, res);

    }
    
    return;
}

bool canJump(vector<int>& nums) {
    int farthest = -1;
    int len = (int)nums.size();
    for (int i = 0; i < len; ++i) {
        if (i + nums[i] > farthest)
            farthest = i + nums[i];
        if (farthest >= len-1)
            return true;
        if (farthest < i+1)
            return false;
    }
    return false;
}


// This runs crazy haha... N^N
int jump_V1(vector<int> &nums) {
    vector<int> res;
    jump_Helper(nums, 0, 0,  res);
    int min = INT_MAX;
    //cout << res.size() << endl;
    for (int i = 0; i < (int)res.size(); ++i) {
        //cout << res[i] << endl;
        if (res[i] < min)
            min = res[i];
    }
    
    return min;
}

// OK, Try using DP here... But still exceeds the time limit...
int jump_DP(vector<int> &nums) {
    int len = (int)nums.size();
        vector<int> map(len, 0);
    
    for (int i = 1; i < len; ++i) {
        int min = INT_MAX;
        for (int j = 0; j < i; ++j) {
            if (map[j] < min && nums[j] + j >= i)
                min = map[j];
        }
        map[i] = min+1;
    }
    return map[len-1];
}

// One... Last... Try...
int jump_Greedy(vector<int> &nums) {
    int start = 0;
    int end = 0;
    int steps = 0;
    int len = (int)nums.size();
    if (len == 1)
        return 0;
    
    while (end < len-1) {
        ++steps;
        int farthest = 0;
        for (int i = start; i <= end; ++i) {
            
            if (nums[i]+i > farthest)
                farthest = nums[i]+i;
        }
        start = end + 1;
        end = farthest;
    }
    
    return steps;
    
}
