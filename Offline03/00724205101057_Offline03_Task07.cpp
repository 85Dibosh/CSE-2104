#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int>& arr, int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = low;
    vector<int> temp(arr.size());

    while(i <= mid && j <= high){
        if(arr[i] > arr[j]){
            temp[k] = arr[j];
            j++;
        }else{
            temp[k] = arr[i];
            i++;
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

    for(int x = low; x < high; x++){
        arr[x] = temp[x];
    }
}

void MergeSort(vector<int>& arr, int low,int high){
    if(low < high){
        int mid = low + (high - low) / 2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
}
int main(){
    int n1,n2;
    cin >> n1;
    vector<int> arr01(n1);
    for(int &x : arr01) cin >> x;
    cout << endl;
    cin >> n2;
    vector<int> arr02(n2);
    for(int &x : arr02) cin >> x;

    vector<int> combined;
    for(int x: arr01) combined.push_back(x);
    for(int x: arr02) combined.push_back(x);

    MergeSort(combined,0,combined.size()-1);

    cout << "Merged Array: ";
    for(int x : combined) cout << x << " ";
    cout << endl;

    int totalSize = combined.size();
    double median;

    if(totalSize % 2 != 0){
        median = combined[totalSize/2];
    }else{
        median = (combined[totalSize/2]+combined[(totalSize/2)-1])/2;
    }

    cout << "Median " << fixed << setprecision(2) << median ;
    return 0;


}
