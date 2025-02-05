# Generate Binary String Without Adjacent zero

## Problem Details
| Source | Problem Link | Problem No| 
|------------|-------------|-------------|
| LeetCode | [ Generate Binary String Without Adjacent zero ](https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/description/) | 3211 |

## Problem Statement
You are given a positive integer n.

A binary string x is valid if all 
substrings
 of x of length 2 contain at least one "1".

Return all valid strings with length n, in any order.

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
