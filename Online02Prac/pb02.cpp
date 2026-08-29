<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

void kSortedInsertionSort(vector<int>& arr,int k){
    int n = arr.size();
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        int limit = max(0 , i - k);
        while ( j >= limit && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int n,k;
    cin >> n;
    cin >> k;

    vector<int> arr;
    for(int i = 0; i < n; i++){
        int x;
        cin >>x;
        arr.push_back(x);
    }

    kSortedInsertionSort(arr,k);
    for(int x : arr){
        cout << x << " ";
    }
}
=======
#include <bits/stdc++.h>
using namespace std;

void kSortedInsertionSort(vector<int>& arr,int k){
    int n = arr.size();
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        int limit = max(0 , i - k);
        while ( j >= limit && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int n,k;
    cin >> n;
    cin >> k;

    vector<int> arr;
    for(int i = 0; i < n; i++){
        int x;
        cin >>x;
        arr.push_back(x);
    }

    kSortedInsertionSort(arr,k);
    for(int x : arr){
        cout << x << " ";
    }
}
>>>>>>> 67ccba7888c88fe56215867cfa8c3c8d10d63ff5
