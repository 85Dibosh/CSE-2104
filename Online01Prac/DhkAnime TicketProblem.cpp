<<<<<<< HEAD
#include <iostream>
using namespace std;

void copyArray(int o[], int c[],int n){
    for(int i = 0; i < n; i++){
        c[i] = o[i];
    }
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
int linearSearch(int arr[],int n, int target){
   for(int i = 0; i < n; i++){
        if(target == arr[i])
            return i;
   }
   return -1;
}

int binarySearch(int arr[], int n, int target){
    int low = 0;
    int high = n-1;

    while(low <= high){
        int mid = (low+high)/2;

        if(target == arr[mid]){
            return mid;
        }else if(target > arr[mid]){
            low = mid+1;
        }else{
            high = mid-1;
        }
        return -1;
    }
}

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(arr[j] > arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}

void selectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]) minIndex = j;
        }
    swap(arr[i],arr[minIndex]);
    }
}
void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int original[] = {5420, 1102, 9981, 2301, 4455, 1101, 8832};
    int n = sizeof(original) / sizeof(original[0]);
    int arr[n];

    copyArray(original, arr, n);
    cout << "Linear Search Index: " << linearSearch(arr,n,2301) << endl;

    copyArray(original, arr, n);
    bubbleSort(arr,n);
    cout << "Bubble Sorted: ";
    print(arr,n);

    copyArray(original, arr, n);
    selectionSort(arr,n);
    cout << "Selection Sorted: ";
    print(arr,n);

    cout << "Binary Search Index: " << binarySearch(arr,n,4455) << endl;
}
=======
#include <iostream>
using namespace std;

void copyArray(int o[], int c[],int n){
    for(int i = 0; i < n; i++){
        c[i] = o[i];
    }
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
int linearSearch(int arr[],int n, int target){
   for(int i = 0; i < n; i++){
        if(target == arr[i])
            return i;
   }
   return -1;
}

int binarySearch(int arr[], int n, int target){
    int low = 0;
    int high = n-1;

    while(low <= high){
        int mid = (low+high)/2;

        if(target == arr[mid]){
            return mid;
        }else if(target > arr[mid]){
            low = mid+1;
        }else{
            high = mid-1;
        }
        return -1;
    }
}

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(arr[j] > arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}

void selectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]) minIndex = j;
        }
    swap(arr[i],arr[minIndex]);
    }
}
void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int original[] = {5420, 1102, 9981, 2301, 4455, 1101, 8832};
    int n = sizeof(original) / sizeof(original[0]);
    int arr[n];

    copyArray(original, arr, n);
    cout << "Linear Search Index: " << linearSearch(arr,n,2301) << endl;

    copyArray(original, arr, n);
    bubbleSort(arr,n);
    cout << "Bubble Sorted: ";
    print(arr,n);

    copyArray(original, arr, n);
    selectionSort(arr,n);
    cout << "Selection Sorted: ";
    print(arr,n);

    cout << "Binary Search Index: " << binarySearch(arr,n,4455) << endl;
}
>>>>>>> 67ccba7888c88fe56215867cfa8c3c8d10d63ff5
