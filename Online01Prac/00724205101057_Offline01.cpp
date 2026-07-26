#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> arr, int tar, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == tar) {
            return i;
        }
    }
    return -1;
}

int binarySearch(vector<int> arr, int tar, int n) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == tar) {
            return mid;
        } else if (arr[mid] < tar) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int getLowerBound(vector<int> arr, int tar, int n) {
    int low = 0;
    int high = n - 1;

    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= tar) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int getUpperBound(vector<int> arr, int tar, int n) {
    int low = 0;
    int high = n - 1;

    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= tar) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    int n,tar;
    cin >> n;
    vector<int> arr;

    for(int i=0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << "Enter target value: ";
    cin >> tar;

    cout << "Linear Search Index: " << linearSearch(arr, tar, n) << endl;
    cout << "Binary Search Index: " << binarySearch(arr, tar, n) << endl;
    cout << "Lower Bound Index: " << getLowerBound(arr, tar, n) << endl;
    cout << "Upper Bound Index: " << getUpperBound(arr, tar, n) << endl;


}
