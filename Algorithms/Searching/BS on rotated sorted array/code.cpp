#include <bits/stdc++.h>
using namespace std;

int searchInRotatedArray(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    


    
    return -1;
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter rotated sorted array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter target element: ";
    cin >> target;

    int index = searchInRotatedArray(nums, target);
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}