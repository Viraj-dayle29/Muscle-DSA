# Generate Parenthesis

## Problem Details
| Source | Problem Link | Problem No| 
|------------|-------------|-------------|
| LeetCode | [Generate Parenthesis](https://leetcode.com/problems/generate-parentheses/description/)) | 22 |

## Problem Statement
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

## Cpp
```cpp
#include<bits/stdc++.h>
using namespace std;

void addParenthesis(int n,int open,int closed,string current,vector<string> &s){
    if(open == n && closed == n){
        s.push_back(current);
        return; 
    }
    if(open < n){
        addParenthesis(n,open + 1,closed,current + '(',s);
    }
    if(closed < open){
        addParenthesis(n,open,closed + 1,current + ')',s);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> s;
    string current;
    addParenthesis(n,0,0,current,s);
    return s;
}

int main(){
    int n = 2;
    vector<string> s = generateParenthesis(n);
    for(const string &a : s){
        cout<<a<<endl;
    }
}
