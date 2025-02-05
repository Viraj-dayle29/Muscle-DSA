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
