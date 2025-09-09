#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);
        return binarySearch(arr, mid + 1, high, x);
    }
  return -1; // caso que no encuentra
}

int main() {
    vector<int> arr = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = arr.size();
    int index = binarySearch(arr, 0, n - 1, x);
    if (index == -1) cout << "Element is not present in array";
    else cout << "Element is present at index " << index;
    return 0;
}
