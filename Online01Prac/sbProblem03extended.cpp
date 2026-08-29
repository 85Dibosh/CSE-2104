//suppose in the problem 3, i was asked to count the total matching containers for multiple containers that has more than one matching containers. for example 1 2 2 2 3 3 3 3 4 4 5, here i have to count how many times 3 , 4 , 5 are there
// 2 is there 3 times
// 3 is there 4 times
// 4 is there 2 times


#include <iostream>
#include <vector>

using namespace std;

// Custom Upper Bound function (returns first index where arr[mid] > target)
int findUpperBound(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int i = 0;
    while(i < n){
        int currentValue = arr[i];

        int currHighIndex = findUpperBound(arr,currentValue);

        int count = currHighIndex - i;

        if(count > 1){
            cout << currentValue << " is there " << count << " times" << endl;
        }

        i = currHighIndex;
    }

    return 0;
}
