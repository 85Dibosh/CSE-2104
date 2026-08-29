#include <bits/stdc++.h>
using namespace std;
void printArray(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

void doubleSelectionSort(vector<int>& arr){
    int left = 0;
    int right = arr.size() - 1;

    while(left < right){
        int min = left;
        int max = left;
        for(int i = left + 1; i <= right; ++i){
            if(arr[i] < arr[min]) min = i;
            if(arr[i] > arr[max]) max = i;
        }
        swap(arr[min],arr[left]);
        if(max == left) max = min;
        swap(arr[max],arr[right]);
        cout << endl;
        printArray(arr);
        left++;right--;

    }
}


int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Run the bi-directional dual-pivot selection sort
    doubleSelectionSort(arr);

    return 0;
}
