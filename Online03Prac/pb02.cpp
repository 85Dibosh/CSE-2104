#include<bits/stdc++.h>
using namespace std;

int totalCount = 0;
int Partition(vector<int>& arr,int low, int high){
    int medComps = 0;
    if(high - low >= 2){
        int mid = low + (high-low) / 2;

        if(arr[low] > arr[mid]) swap(arr[low],arr[mid]);
        medComps++;
        if(arr[mid] > arr[high]) swap(arr[mid],arr[high]);
        medComps++;
        if(arr[low] > arr[mid]) swap (arr[low],arr[mid]);
        medComps++;

        cout << "Medians of 3 chosen " << arr[mid] << "(Comparisions made to find median : " << medComps << " )" <<endl;

        swap(arr[low] , arr[mid]);
    }
    else if (high - low == 1){
        cout << "Only 2 elements present. Pivot chosen: " << arr[low]
             << " (Comparisons to find median: " << medComps << ")\n";
    }

    totalCount += medComps;


    int pivot = arr[low];
    int i = low;
    int j = high;

    while( i < j ){
        while ( i <= high ){
                totalCount++;
                if(pivot >= arr[i])
                    i++;
                else
                    break;
        }
        while ( j >= low ){
            totalCount++;
            if(pivot < arr[j])
                j--;
            else
                break;
        }

        if( i < j ) swap(arr[i] , arr[j]);
    }
    swap(arr[low] , arr[j]);
    return j;
}

void QuickSort(vector<int>& arr, int low, int high){
    if( low < high ){
        int pI = Partition(arr,low,high);
        QuickSort(arr,low,pI-1);
        QuickSort(arr,pI+1,high);
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x; // always use & in for-each loops when scanning

    QuickSort(arr, 0, n - 1);

    cout << "\n--- Final Results ---\n";
    cout << "Sorted Array: ";
    for (int x : arr) cout << x << " ";

    cout << "\nTotal Comparisons (Median Selection + Partitioning): " << totalCount << "\n";

    return 0;
}



/*
Implement Quick Sort using the median-of-three method (first, middle, last elements) to choose the pivot at each recursive call.
For each recursive call, print which of the three elements was chosen as pivot and how many comparisons were needed just to determine the median.
Report the total comparison count for the whole sort.
*/

/*
[EXECUTION TRACE IN THE IDE DEBUGGER]

--- MAIN ARRAY PASS ---
* Array State: [7, 2, 1, 6, 8, 5] (Bounds: 0 to 5)
* 3 comparisons made sorting index 0(7), index 2(1), and index 5(5).
  >> Sorted to 1, 5, 7. Median is 5.
* Pointers i and j sweep array to partition around 5.
* Pointer i hits 4 comparisons before stopping.
* Pointer j hits 4 comparisons before stopping.
* Array split into Left Child [1, 2] and Right Child [6, 8, 7].
* Pass Total: 3 + 4 + 4 = 11 comparisons. Global Count: 11.

--- LEFT CHILD PASS ---
* Array State: [1, 2] (Bounds: 0 to 1)
* Only 2 elements exist. Skip median sorting.
  >> Pivot is 1.
* Pointer i hits 2 comparisons before going out of bounds.
* Pointer j hits 2 comparisons before stopping on the pivot.
* Pass Total: 0 + 2 + 2 = 4 comparisons. Global Count: 15.

--- RIGHT CHILD PASS ---
* Array State: [6, 8, 7] (Bounds: 3 to 5)
* 3 comparisons made sorting index 3(6), index 4(8), and index 5(7).
  >> Sorted to 6, 7, 8. Median is 7.
* Pointers i and j sweep array to partition around 7.
* Pointer i hits 2 comparisons before stopping.
* Pointer j hits 3 comparisons before stopping.
* Pass Total: 3 + 2 + 3 = 8 comparisons. Global Count: 23.

===============================================================================
[IDE CONSOLE OUTPUT]

--- Recursive Pivot Logs ---
Median of 3 chosen: 5 (Comparisons made to find median: 3)
Only 2 elements present. Pivot chosen: 1 (Comparisons to find median: 0)
Median of 3 chosen: 7 (Comparisons made to find median: 3)

--- Final Results ---
Sorted Array: 1 2 5 6 7 8
Total Comparisons (Median Selection + Partitioning): 23
===============================================================================
*/
