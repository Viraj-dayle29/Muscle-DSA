# Better String

## Problem Details
| Source | Problem Link | Problem No| 
|------------|-------------|-------------|
| GeeksForGeeks | [Better String](https://www.geeksforgeeks.org/problems/better-string/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=better-string/) | null |

## Problem Statement
Given a pair of strings of equal lengths, Geek wants to find the better string. The better string is the string having more number of distinct subsequences.
If both the strings have equal count of distinct subsequence then return str1.

## Cpp
```cpp
#include<bits/stdc++.h>
using namespace std;

void addString(int n,set<string> &ans,string current,int index,string s){
    if(index == n){
        ans.insert(current);
        return;
    }
    addString(n,ans,current,index + 1,s);
    addString(n,ans,current + s[index],index + 1,s);
    current.pop_back();
}

vector<string> distinctString(string s){
    set<string> ans;
    int n = s.size();
    addString(n,ans,"",0,s);
    vector<string> an(ans.begin(),ans.end());
    return an;
}

string betterString(string str1, string str2) {
    if(distinctString(str1).size() >= distinctString(str2).size()){
        return str1;
    }
    return str2;
}

int main(){
    string str1 = "ggg";
    string str2 = "gfg";
    cout<<betterString(str1,str2);
}
