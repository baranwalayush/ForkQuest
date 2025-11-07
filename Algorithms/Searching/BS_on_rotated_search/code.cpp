#include <bits/stdc++.h>
using namespace std;

int searchInRotatedArray(vector<int>& nums, int target) 
    {
        int n=nums.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

     
        if (nums[low] <= nums[mid]) {
            if (target >= nums[low] && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
       
        else {
            if (target > nums[mid] && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;  // Not found
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