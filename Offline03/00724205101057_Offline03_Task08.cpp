#include <bits/stdc++.h>
using namespace std;

int compCount = 0;
void Merge(vector<int>& arr, int low, int mid , int high){
    int i = low;
    int j = mid + 1;
    int k = low;

    vector<int> temp(arr.size());
    while(i <= mid && j <= high){
        compCount++;
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j <= high){
        temp[k] = arr[j];
        j++;
        k++;
    }
    for(int x = low; x <= high; x++){
        arr[x] = temp[x];
    }
}

void MergeSort(vector<int>&arr, int low, int high){
    if(low < high){
        int mid = low + (high - low) / 2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid + 1,high);
        Merge(arr,low,mid,high);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr){
        cin >> x;
    }
    MergeSort(arr,0,n-1);
    cout << "Total Comparisons " << compCount << endl;
    return 0;
}
