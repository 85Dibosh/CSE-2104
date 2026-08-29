#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int>& arr,int low,int mid,int high){
    int i = low;
    int j = mid+1;
    int k = low; // not needed if vector is used

    vector<int> temp;
    while(i <= mid && j<= high){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
        k++;
    }

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
        k++;
    }

    while(j <= high){
        temp.push_back(arr[j]);
        j++;
        k++;
    }

    for(int x=low; low < high; x++){
        arr[x] = temp[x];
    }
}

void MergeSort(vector<int>& arr,int low, int high){
    if(low<high){
        int mid = low + (high-low)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
}

void Partition(vector<int>& arr,int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){
        while(pivot >= arr[i] && i < high) i++;
        while(pivot < arr[j] && j > low) j--;

        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j; // since it comes down to the next pivot, j is used as the next partition index

}

void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int partitionIndex = Partition(arr,low,high);
        quickSort(arr,low,partitionIndex - 1);
        quickSort(arr,partitionIndex + 1, high);
    }
}

void selectionSort(vector<int>& arr,int n){
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        swap(arr[i],arr[j]);
    }
}

void insertionSort(vector<int>& arr, int n){
    for(int i = 1; i < n; i++ ){
        int key = arr[i];
        int j = j - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

