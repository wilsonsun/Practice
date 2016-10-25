//
//  main.cpp
//  Sums
//
//  Created by Wilson Sun on 2016-10-24.
//  Copyright © 2016 Wilson Sun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/*
 *Given array S = [1, 2, 1, 5, 4, 3, 3], return [[2, 4], [3, 3]]
 */

// Method to print list of list
void printLofL(vector<vector<int>> &v) {
    cout << '[';
    for (int i = 0; i < v.size(); ++i) {
        cout << '[';
        cout << v[i][0];
        for (int j = 1; j < v[i].size(); ++j)
            cout << ',' << v[i][j];
        cout << ']';
        if (i != v.size()-1)
            cout << ',';
    }
    cout << ']' << endl;
    
}

// Version 1: Using hash table, time complexity O(n), space complexity O(n)
vector<vector<int>> twoSum_V1(vector<int> &nums, int sum) {
    unordered_map<int, int> hashMap;
    unsigned long len = nums.size();
    vector<vector<int>> res;
    
    for (int i = 0; i < len; ++i)
        hashMap[nums[i]]++;
    
    
    for (int i = 0; i < len; ++i) {
        int index = sum - nums[i];
        unordered_map<int, int> hM_temp = hashMap;
        if (hM_temp[nums[i]] > 0) {
            if (hashMap[index] > 0) {
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(index);
                res.push_back(temp);
                hM_temp[nums[i]]--;
                hM_temp[index]--;
            }
        }
    }
    
    return res;
}

// Version 2: Using two pointers' method, time complexity O(nlogn), space complexity O(1)
vector<vector<int>> twoSum_V2(vector<int> &nums, int sum) {
    int len = (int)nums.size();
    int front = 0;
    int back = len-1;
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    
    while (front < back) {
        if (front > 0 && nums[front] == nums[front-1]) {
            front++;
            continue;
        }
        if (nums[front] + nums[back] > sum)
            back--;
        else if (nums[front] + nums[back] < sum)
            front++;
        else {
            vector<int> temp;
            temp.push_back(nums[front]);
            temp.push_back(nums[back]);
            res.push_back(temp);
            front++;
            back--;
        }
    }
    
    return res;
}

// What about ksum??? k >= 2

vector<vector<int>> twoSum_V1_VAR(vector<int> &nums, int sum, unordered_map<int, int> hashMap) {
    int len = (int)nums.size();
    vector<vector<int>> res;
    
    for (int i = 0; i < len; ++i) {
        unordered_map<int, int> hM_temp = hashMap;
        int index = sum - nums[i];
        // Special case here
        if (nums[i] == index && hM_temp[index] > 1) {
            hM_temp[index] -= 2;
        } else if (nums[i] != index && hM_temp[nums[i]] > 0 && hM_temp[index] > 0) {
            vector<int> temp;
            temp.push_back(nums[i]);
            temp.push_back(index);
            res.push_back(temp);
            hM_temp[nums[i]]--;
            hM_temp[index]--;
        }
    }
    
    return res;
}

vector<vector<int>> kSum_Helper(vector<int> &nums, int sum, int k, unordered_map<int, int> hashMap) {
    int len = (int)nums.size();
    
    if (k == 2) {
        vector<vector<int>> a =twoSum_V1_VAR(nums, sum, hashMap);
        return a;
    }
    vector<vector<int>> res;
    
    for (int i = 0; i < len; ++i) {
        
        vector<vector<int>> temp = kSum_Helper(nums, sum-nums[i], k-1, hashMap);
        
        if (temp.size() != 0) {
            for (int j = 0; j < temp.size(); ++j) {
                // Each vector should maintain a hashtable
                unordered_map<int, int> hM_temp = hashMap;
                for (int k = 0; k < temp[j].size(); ++k) {
                    hM_temp[temp[j][k]]--;
                }
                
                if (hM_temp[nums[i]] > 0) {
                    hM_temp[nums[i]]--;
                    temp[j].push_back(nums[i]);
                    res.push_back(temp[j]);
                }
            }
        }
    }
    
    return res;
}

// This Version will produce duplicates
vector<vector<int>> kSum_V1(vector<int> &nums, int sum, int k) {
    unordered_map<int, int> hashMap;
    int len = (int)nums.size();
    for (int i = 0; i < len; ++i)
        hashMap[nums[i]]++;
    return kSum_Helper(nums, sum, k, hashMap);
}


vector<vector<int>> kSum_V2_Helper(vector<int> &nums, int sum, int k) {
    if (k < 2)
        return {{0}};
    if (k == 2)
        return twoSum_V2(nums, sum);

    int len = (int)nums.size();
    vector<vector<int>> res;
    
    for (int i = 0; i < len; ++i) {
        if (i > 0 && nums[i] == nums[i-1])
            continue;
        vector<vector<int>> temp = kSum_V2_Helper(nums, sum-nums[i], k-1);
        int temp_len = (int)temp.size();
        for (int j = 0; j < temp_len; ++j) {
            vector<int> temp_j = temp[j];
            temp_j.push_back(nums[i]);
            res.push_back(temp_j);
        }
    }
    
    return res;
}

vector<vector<int>> kSum_V2(vector<int> &nums, int sum, int k) {
    sort(nums.begin(), nums.end());
    return kSum_V2_Helper(nums, sum, k);
}


int main(int argc, const char * argv[]) {
    vector<int> S = {1,1,3, 3,1,1,2, 6, 7, 8, 9, 1};
    vector<vector<int>> t = kSum_V2(S, 5, 4);
    printLofL(t);
    
    return 0;
}
