<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr){
    int n = arr.size();

    for(int i = 1; i < n; ++i){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j= j-1;
        }
        arr[j+1] = key;
    }
}
int main(){
    int n;
    cin >> n;

    vector<int> arr;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    insertionSort(arr);
    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i];
    }
}

=======
#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr){
    int n = arr.size();

    for(int i = 1; i < n; ++i){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j= j-1;
        }
        arr[j+1] = key;
    }
}
int main(){
    int n;
    cin >> n;

    vector<int> arr;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    insertionSort(arr);
    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i];
    }
}

>>>>>>> 67ccba7888c88fe56215867cfa8c3c8d10d63ff5
