// SELECTION SORT

#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}


void print(int arr[], int size){
    for(int i=0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
}
int main(){
    int arr[] = {13,11,14,5,1};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "intial arr: ";
    print(arr,size);
    selectionSort(arr,size);
    cout << "sorted arr: ";
    print(arr,size);
}

