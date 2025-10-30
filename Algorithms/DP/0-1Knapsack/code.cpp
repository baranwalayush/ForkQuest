#include <iostream>
#include <vector>
using namespace std;

int knapsack(int n, int W, vector<int>& wt, vector<int>& val) {
    
    
    

    
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++) cin >> wt[i];
    for (int i = 0; i < n; i++) cin >> val[i];

    cout << knapsack(n, W, wt, val) << endl;
    return 0;
}
