#include<bits/stdc++.h>
using namespace std;

int getDigit(int num){
    return num%10;
}

void insertionSortByDigit(vector<int>& arr){
    int n = arr.size();
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;

        while( j >= 0 && (getDigit(arr[j]) > getDigit(key))){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    insertionSortByDigit(arr);
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
