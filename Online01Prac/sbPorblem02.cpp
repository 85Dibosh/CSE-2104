<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int>& arr, int tar){
    int n= arr.size();
    int l=0;
    int h=n-1;
    while(l <= h){
        int m = l+(h-l)/2;
        if(arr[m] == tar){
            return m;
        }else if(arr[m] > tar) h = m -1;
        else l = m + 1;
    }
    return -1;
}

int getLowerBound(const vector<int>& arr, int tar){
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size() - 1;

    while(low <= high){
        int mid = low+(high-low)/2;

        if(arr[mid] >= tar){
                ans = mid;
                high = mid - 1;
        }else{
                low = mid + 1;
        }
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

    int found = binarySearch(arr,tar);
    int inID = getLowerBound(arr,tar);

    if(!(found == -1)) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    cout << inID << endl;


}
=======
#include <bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int>& arr, int tar){
    int n= arr.size();
    int l=0;
    int h=n-1;
    while(l <= h){
        int m = l+(h-l)/2;
        if(arr[m] == tar){
            return m;
        }else if(arr[m] > tar) h = m -1;
        else l = m + 1;
    }
    return -1;
}

int getLowerBound(const vector<int>& arr, int tar){
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size() - 1;

    while(low <= high){
        int mid = low+(high-low)/2;

        if(arr[mid] >= tar){
                ans = mid;
                high = mid - 1;
        }else{
                low = mid + 1;
        }
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

    int found = binarySearch(arr,tar);
    int inID = getLowerBound(arr,tar);

    if(!(found == -1)) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    cout << inID << endl;


}
>>>>>>> 67ccba7888c88fe56215867cfa8c3c8d10d63ff5
