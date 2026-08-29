#include <bits/stdc++.h>
using namespace std;

int getDigit(int num, int n){
    for(int i =1; i < n; i++){
        num /= 10;
    }
    return num%10;
}

void SortDigit(vector<int>& arr, int nPos){
    int size = arr.size();
    for(int i = 1; i < size; i++){
        int val = arr[i];
        int d1 = getDigit(val,nPos);
        int j = i - 1;

        while(j >=0 && getDigit(arr[j],nPos) > d1){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = val;

    }
}

int main(){
    int len,nPos;
    cin >> len;
    cin >> nPos;

    vector<int> arr(len);
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    SortDigit(arr, nPos);

    for (int i = 0; i < len; i++) {
        cout << arr[i] << (i == len - 1 ? "" : " ");
    }
    cout << "\n";
}
