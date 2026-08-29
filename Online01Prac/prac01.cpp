<<<<<<< HEAD
// BUBBLE SORT

#include <iostream>
using namespace std;

int bubblesort(int arr[],int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
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
    bubblesort(arr,size);
    cout << "sorted arr: ";
    print(arr,size);
}
=======
// BUBBLE SORT

#include <iostream>
using namespace std;

int bubblesort(int arr[],int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
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
    bubblesort(arr,size);
    cout << "sorted arr: ";
    print(arr,size);
}
>>>>>>> 67ccba7888c88fe56215867cfa8c3c8d10d63ff5
