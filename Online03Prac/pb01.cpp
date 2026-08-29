//Given an array of N integers, simulate Quick Sort using the first element as pivot instead of the last, and count the number of comparisons performed. Compare your comparison count with the "last element as pivot" version on the same array and explain any difference.
#include <bits/stdc++.h>
using namespace std;

int compCount = 0;
int Partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j)
    {
        while( i <= high && pivot >= arr[i]) // use this logic during counts to properly count all nums and better to divide the last logic in if statement and keep count outside of if
        {
            i++;
            compCount++;
        }
        while( j >= low && pivot < arr[j]) // use this logic during counts to properly count all nums
        {
            j--;
            compCount++;
        }

        if( i < j ) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void QuickSort(vector<int>& arr, int low, int high)
{
    if(low < high)
    {
        int pI = Partition(arr,low,high);
        QuickSort(arr,low,pI-1);
        QuickSort(arr,pI+1,high);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    QuickSort(arr,0,n-1);

    cout << "Total Comparisons (First Element Pivot): " << compCount << "\n";
    return 0;
}

