#include <bits/stdc++.h>
using namespace std;
vector<int> arr;

void print(const vector<int>& arr){
    for(int x : arr){
        cout << x << " ";
    }
}
//void swap(int a,int b){
//    int temp = a;
//    a = b;
//    b = temp;
//}
void selectionSort(vector<int>& arr){
    int n = arr.size();
    for(int i=0; i < n-1; i++){
        int min = i;
        for(int j=i+1; j < n; j++){
            if(arr[j] < arr[min]) min = j;
        }
    if(min != i) swap(arr[i],arr[min]);
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << "Original Array: ";
    print(arr);

    cout << "Selection Sorted Array: ";
    selectionSort(arr);
    print(arr);

}
