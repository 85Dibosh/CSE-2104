<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

int getLowerBound(const vector<int>& arr, int& tar,int n){
    int low = 0;
    int high = n - 1;
    int ans = n - 1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(arr[mid] >= tar){
            ans = mid;
            high = mid  - 1;
        }else low = mid + 1;
    }
    return ans;
}

int getUpperBound(const vector<int>& arr, int& tar,int n){
    int low = 0;
    int high = n - 1;
    int ans = n - 1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(arr[mid] > tar){
            ans = mid;
            high = mid  - 1;
        }else low = mid + 1;
    }
    return ans;
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

    int tar;
    cin >> tar;

    int count = getUpperBound(arr,tar,n) - getLowerBound(arr,tar,n);

    cout << "Repeated between LowHigh: " << count << endl;
    return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;

int getLowerBound(const vector<int>& arr, int& tar,int n){
    int low = 0;
    int high = n - 1;
    int ans = n - 1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(arr[mid] >= tar){
            ans = mid;
            high = mid  - 1;
        }else low = mid + 1;
    }
    return ans;
}

int getUpperBound(const vector<int>& arr, int& tar,int n){
    int low = 0;
    int high = n - 1;
    int ans = n - 1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(arr[mid] > tar){
            ans = mid;
            high = mid  - 1;
        }else low = mid + 1;
    }
    return ans;
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

    int tar;
    cin >> tar;

    int count = getUpperBound(arr,tar,n) - getLowerBound(arr,tar,n);

    cout << "Repeated between LowHigh: " << count << endl;
    return 0;
}
>>>>>>> 67ccba7888c88fe56215867cfa8c3c8d10d63ff5
