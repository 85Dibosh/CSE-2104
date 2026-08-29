#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> vec,int tar){
    for(int i = 0; i < vec.size(); i++){
        if(tar == vec[i])
            return i;
    }
    return -1;
}
int binarySearch(vector<int> vec,int tar){
    int low = 0;
    int high = vec.size()-1;

    while(low <= high){
        int mid = low+(high-low)/2;

        if(tar == vec[mid]){
            return mid;
        }else if(tar > vec[mid]){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1;
}

int res1 = 0;
int modLowerBoundBinarySearch(vector<int> vec,int tar){
    int low = 0;
    int high = vec.size()-1;

    while(low <= high){
        int mid = low+(high-low)/2;

        if(tar == vec[mid]){
            res1 =  mid;
            high = mid - 1;
        }else if(tar > vec[mid]){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return res1;
}
int n1;
int res2 = n1-1 ;
int modUpperBoundBinarySearch(vector<int> vec,int tar){
    int low = 0;
    int high = vec.size()-1;

    while(low <= high){
        int mid = low+(high-low)/2;

        if(tar == vec[mid]){
            res2 =  mid;
            low = mid + 1;
        }else if(tar > vec[mid]){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return res2;
}
vector<int> vecGlobal;
int main(){
    vector<int> vecLocal;
    int n,x,target;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        vecLocal.push_back(x);
    }
    vecLocal.push_back(100);
    int n1 = vecLocal.size();
    for(int i = 0; i < vecLocal.size(); i++){
        cout << vecLocal[i] << " ";
    }
    cout << endl << "Target: " ;
    cin >> target ;

    cout << "Target found at index: " << linearSearch(vecLocal,target) << endl;
    cout << "Target found at index: " << binarySearch(vecLocal,target) << endl;
    cout << "Target found at index: " << modLowerBoundBinarySearch(vecLocal,target) << endl;
    cout << "Target found at index: " << modUpperBoundBinarySearch(vecLocal,target) << endl;
    return 0;
}
