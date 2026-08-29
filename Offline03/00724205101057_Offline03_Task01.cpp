#include <bits/stdc++.h>
using namespace std;

int compCount = 0;

int Partition(vector<int>& arr,int low, int high){

    swap(arr[low],arr[high]);

    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){
        while(pivot >= arr[i] && i < high){
                compCount++;
                i++;
        }
        while(pivot < arr[j] && j >= low ){
                compCount++;
                j--;
        }
        if(i < j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
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
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    quickSort(arr,0,n-1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " " ;
    }
    cout << "\n" << "Total Comparisons Made: " << compCount;
    return 0;
}
