#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b) {
    while (a != b) {
        if (a > b)
            a = a - b;
        else
            b = a - b; 
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}
