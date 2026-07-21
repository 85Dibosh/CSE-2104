#include <bits/stdc++.h>
using namespace std;

void mergeArray(vector<int>& arr, int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = low;

    vector<int> temp(arr.size());
    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
        }else{
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

void mergeSort(vector<int>& arr,int low, int high){
    if(low < high){
        int mid = (low+high) / 2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        mergeArray(arr,low,mid,high);
    }
}
int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    mergeSort(arr,0,n-1);
    cout << endl;

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
