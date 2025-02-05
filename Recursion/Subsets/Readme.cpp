# Subsets

## Problem Details
| Source | Problem Link | Problem No| 
|------------|-------------|-------------|
| LeetCode | [ Subsets ](https://leetcode.com/problems/subsets/description/) | 78 |

## Problem Statement
Given an integer array nums of unique elements, return all possible 
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

## Cpp
```cpp
#include<bits/stdc++.h>
using namespace std;

void add_binary(set<string> &s, string current, char start, int n) {
    if (current.size() == n) {  // Base case: If string reaches length n, add to result
        s.insert(current);  // Use insert to avoid duplicates
        return;
    }

    current.push_back(start);  // Add current character
    
    if (start == '0') {
        add_binary(s, current, '1', n);  // Next character must be '1'
    } else {
        add_binary(s, current, '1', n);  // '1' can be followed by '1'
        add_binary(s, current, '0', n);  // '1' can be followed by '0'
    }
}

vector<string> validStrings(int n) {    
    set<string> s;  // Change vector to set
    string current = "";
    add_binary(s, current, '0', n); 
    add_binary(s, current, '1', n);
    
    vector<string> result(s.begin(), s.end());
    return result;
}

int main() {
    int n = 2;
    vector<string> s = validStrings(n);
    for (const string &a : s) {
        cout << a << " ";
    }
}
