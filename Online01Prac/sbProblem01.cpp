#include <bits/stdc++.h>
using namespace std;

int linearSearch(const vector<int>& arr, int tar, int& lc){
    int n= arr.size();
    for(int i =0; i < n; i++){
        lc++;
        if(arr[i] == tar){
            return i;
        }
    }
    return -1;
}

int binarySearch(const vector<int>& arr, int tar, int& bc){
    int n= arr.size();
    int l=0;
    int h=n-1;
    while(l <= h){
        bc++;
        int m = l+(h-l)/2;
        if(arr[m] == tar){
            return m;
        }else if(arr[m] > tar) h = m -1;
        else l = m + 1;
    }
    return -1;
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

        int lc=0, bc = 0;

        int ld = linearSearch(arr,tar,lc);
        int bd = binarySearch(arr,tar,bc);
        cout << "Linear Search Index: " << ld << " (Comparisons: " << lc << ")" << endl;
        cout << "Binary Search Index: " <<  bd << " (Comparisons: " << bc << ")" << endl;

        return 0;

}
