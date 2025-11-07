#include <bits/stdc++.h>
using namespace std;

// Bitwise addition
int bitwiseAdd(int a, int b) {
    

    
}

// Bitwise subtraction
int bitwiseSubtract(int a, int b) {
    



}

// Bitwise multiplication
int bitwiseMultiply(int a, int b) {
   

    
}
// Bitwise division
int bitwiseDivide(int dividend, int divisor) {
    




}

int main() {
    int a, b;
    char op;
    cout << "Enter expression (a op b): ";
    cin >> a >> op >> b;

    switch (op) {
        case '+': cout << bitwiseAdd(a, b); break;
        case '-': cout << bitwiseSubtract(a, b); break;
        case '*': cout << bitwiseMultiply(a, b); break;
        case '/': cout << bitwiseDivide(a, b); break;
        default: cout << "Invalid operator!";
    }
    cout << endl;
}
