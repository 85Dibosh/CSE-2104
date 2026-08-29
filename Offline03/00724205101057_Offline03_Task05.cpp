#include <bits/stdc++.h>
using namespace std;

int Partition(vector<int>& arr, int low, int high){
    int pivot = arr[low];

    int i = low;
    int j = high;

    while(i < j){
        while(pivot >= arr[i] && i < high) i++;
        while(pivot < arr[j] && j > low) j--;
        if(i < j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    cout << "Pivot " << pivot << " placed at final index " << j << endl;
    return j;
}
void quickSort(vector<int>& arr, int low, int high){
        if(low < high){
            int pI = Partition(arr,low,high);
            quickSort(arr,low,pI-1);
            quickSort(arr,pI+1,high);
        }
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr) cin >> x;
    quickSort(arr,0,n-1);
    cout << endl;
    for(int &x : arr) cout << x << " ";
    return 0;
}
