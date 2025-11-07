#include <bits/stdc++.h>
using namespace std;

long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

long long comb(int n, int r){
    long long result = factorial(n)/(factorial(n-r) * factorial(r));

    return result;
}


int main() {
    int n, r;
    cin >> n;
    cin >> r;
    cout << factorial(n) << endl;
    cout << comb(n, r);
    return 0;
}
