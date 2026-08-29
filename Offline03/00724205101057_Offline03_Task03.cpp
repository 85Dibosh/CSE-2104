#include <bits/stdc++.h>
using namespace std;

int swapCount = 0;

int Partition(vector<int>& arr, int low, int high){
    int pivot = arr[low];

    int i = low;
    int j = high;
    while(i < j){
        while(pivot >= arr[i] && i < high) i++;
        while(pivot < arr[j] && j > low) j--;

        if(i < j){
            swap(arr[i],arr[j]);
            swapCount++;
        }
    }

    swap(arr[low],arr[j]);
    swapCount++;
    return j;
}

void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int pivotIndex = Partition(arr,low,high);

        quickSort(arr,low,pivotIndex-1);
        quickSort(arr,pivotIndex+1,high);
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i < n; i++){
        cin >> arr[i];
    }

    quickSort(arr,0,n-1);
    for(int x : arr){
        cout << x << " ";
    }
    cout << "Net Swaps: " << swapCount;
    return 0;
}
