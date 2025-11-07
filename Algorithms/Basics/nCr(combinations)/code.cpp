// #include <bits/stdc++.h>
#include<iostream>
using namespace std;

long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact =fact* (long long)i;
    }
    return fact;
}

int main() {
    int n;
    int r;
    cin >> n;
    cin>>r;
    // cout << factorial(n) << endl;
    long long combination= factorial(n)/(factorial(r)*factorial(n-r));
    cout<<combination;
    return 0;
}
