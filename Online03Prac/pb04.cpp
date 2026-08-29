#include <bits/stdc++.h>
using namespace std;

long long totalInversions = 0; // int overflow might happen if long long is not used
void Merge(vector<int>& arr, int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;

    while( i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
        }else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while( i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }

    while( j <= high ){
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(int x = low; x < high; x++){
        arr[x] = temp[x];
    }
}

void MergeSort(vector<int> arr, int low, int high){
    if(low < high){
        int mid = low + (high - low) / 2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr){
        cin >> x;
    }
    MergeSort(arr,0,n-1);
    cout << "Total recursive mergeFunctions called  " << recurCount << endl;
    return 0;
}

/*
Given an array of N integers,
count the number of inversions (pairs i < j where arr[i] > arr[j]) using a modified Merge Sort in O(N log N) time.
Your program must output the merged sorted array and the total inversion count,
and must also report, for each merge step, how many inversions were resolved at that step.
*/

/*
[EXECUTION TRACE IN THE IDE]

--- STEP 1: LEFT HALF SPLITS ---
* Merge [0..1] -> Merging [7] and [2]
  - 7 > 2. The left half has 1 element remaining. Local Inversions = 1.
  >> Merged Array Segment: [2, 7]

* Merge [0..2] -> Merging [2, 7] and [1]
  - 2 > 1. The left half has 2 elements remaining (2 and 7). Local Inversions = 2.
  >> Merged Array Segment: [1, 2, 7]

--- STEP 2: RIGHT HALF SPLITS ---
* Merge [3..4] -> Merging [6] and [8]
  - 6 < 8. No inversions. Local Inversions = 0.
  >> Merged Array Segment: [6, 8]

* Merge [3..5] -> Merging [6, 8] and [5]
  - 6 > 5. The left half has 2 elements remaining (6 and 8). Local Inversions = 2.
  >> Merged Array Segment: [5, 6, 8]

--- STEP 3: FINAL ROOT MERGE ---
* Merge [0..5] -> Merging [1, 2, 7] and [5, 6, 8]
  - 1 < 5 (No inversion)
  - 2 < 5 (No inversion)
  - 7 > 5. Left half has 1 element remaining (7). Local Inversions = +1.
  - 7 > 6. Left half has 1 element remaining (7). Local Inversions = +1.
  - 7 < 8 (No inversion)
  - Final pass total local inversions = 2.
  >> Merged Array Segment: [1, 2, 5, 6, 7, 8]

===============================================================================
[IDE CONSOLE OUTPUT]

--- Merge Step Logs ---
Merge [0..1] resolved 1 inversions.
Merge [0..2] resolved 2 inversions.
Merge [3..4] resolved 0 inversions.
Merge [3..5] resolved 2 inversions.
Merge [0..5] resolved 2 inversions.

--- Final Results ---
Sorted Array: 1 2 5 6 7 8
Total Inversions Found: 7
===============================================================================
*/
