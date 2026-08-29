#include <bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int>& arr, int tar, int& n){
    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if ( arr[mid] == tar){
            return mid;
        }else if(arr[mid] > tar) high = mid - 1;
        else low = mid  + 1;
    }
}
int getUpperBound(const vector<int>& arr, int tar, int& n){
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if ( arr[mid] > tar){
            ans = mid;
            high = mid - 1;
        }else low = mid + 1;
    }
    return ans;
}
int main(){
    int n1,n2,tar;
    cin >> n1;
    cin >> n2;

    vector<int> arr;
    for(int i = 0; i < n1; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    for(int i = 0; i < n2; i++){
        cin >> tar;
        cout << getUpperBound(arr,tar,n1);
        cout << endl;
    }
}
