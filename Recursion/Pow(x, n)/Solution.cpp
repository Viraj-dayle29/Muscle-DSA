#include<iostream>
using namespace std;

double myPow(double x, int n) {

    double ans = 1.0;
    long long nn = n;

    nn = (n < 0) ? -nn : nn;
    while(nn){
        if(nn % 2 == 1){
            ans = ans * x;
            nn = nn-1;
        }
        x = x * x;
        nn = nn / 2;
    }
    return (n < 0) ? (1.0000 /ans ) : ans;
}

int main(){
    double x = 2.00000;
    int n = 10;
    cout<<myPow(x,n);
}