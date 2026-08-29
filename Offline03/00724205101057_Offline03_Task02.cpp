#include <bits/stdc++.h>
using namespace std;

void rearrangeAroundPivot(vector<int>& arr,int pivot){
    int n = arr.size();

    int pivotIndex = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] = pivot){
            pivotIndex = i;
            break;
        }
    }

    if(pivotIndex == -1){
        cout << "Pivot not found.";
        return;
    }

    swap(arr[0],arr[pivotIndex]);

    int i = 0;
    int j = n - 1;
    while(i < j){
        while(pivot >= arr[i] && i < n-1) i++;
        while(pivot < arr[j] && j > 0) j--;

        if(i < j) swap(arr[i],arr[j]);
    }

    swap(arr[0],arr[j]);
}

int main(){
    int n,pivot;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << endl;
    cin >> pivot;

    rearrangeAroundPivot(arr,pivot);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;

}
