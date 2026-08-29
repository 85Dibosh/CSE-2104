<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
int getLowerBound(const vector<int>& arr, int tar, int& n){
    int low = 0;
    int high = n - 1;

    int ans = n - 1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(arr[mid] >= tar){
            ans = mid;
            high = mid - 1;
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

    int rBound = getLowerBound(arr,tar,n);
    int lBound = rBound - 1;

    int chosen = -1;

    if(rBound == 0) chosen = 0;
    else if(rBound == n) chosen = n - 1;
    else{
        int leftDiff = abs(arr[rBound] - tar);
        int rightDiff = abs(arr[rBound] - tar);

        if(leftDiff <= rightDiff) chosen = lBound;
        else chosen = rBound;
    }

    cout << "Closest Occupied Bay Index: " << chosen << endl;
    cout << "Bay Coordinate Value: " << arr[chosen] << endl;
    cout << "Absolute Distance: " << abs(arr[chosen] - tar) << endl;

    return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;
int getLowerBound(const vector<int>& arr, int tar, int& n){
    int low = 0;
    int high = n - 1;

    int ans = n - 1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(arr[mid] >= tar){
            ans = mid;
            high = mid - 1;
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

    int rBound = getLowerBound(arr,tar,n);
    int lBound = rBound - 1;

    int chosen = -1;

    if(rBound == 0) chosen = 0;
    else if(rBound == n) chosen = n - 1;
    else{
        int leftDiff = abs(arr[rBound] - tar);
        int rightDiff = abs(arr[rBound] - tar);

        if(leftDiff <= rightDiff) chosen = lBound;
        else chosen = rBound;
    }

    cout << "Closest Occupied Bay Index: " << chosen << endl;
    cout << "Bay Coordinate Value: " << arr[chosen] << endl;
    cout << "Absolute Distance: " << abs(arr[chosen] - tar) << endl;

    return 0;
}
>>>>>>> 67ccba7888c88fe56215867cfa8c3c8d10d63ff5
