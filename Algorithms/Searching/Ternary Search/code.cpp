#include <bits/stdc++.h>
using namespace std;

int ternarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        // Divide array into 3 parts
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == target) return mid1;
        if (arr[mid2] == target) return mid2;

        if (target < arr[mid1]) 
            right = mid1 - 1;          // Search in left third
        else if (target > arr[mid2]) 
            left = mid2 + 1;           // Search in right third
        else 
            left = mid1 + 1, right = mid2 - 1;  // Search in middle third
    }

    return -1; // Not found
}

int main() {
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> x;

    int index = ternarySearch(arr, x);
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}