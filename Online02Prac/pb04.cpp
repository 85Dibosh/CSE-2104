#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vec;

    for(int i = 0; i < n; ++i){
        int val,count=0;
        cin >> val;

        vec.push_back(val);
        int j = vec.size() - 2;
        while( j >= 0 && vec[j] > val){
            vec[j+1] = vec[j];
            count++;
            j--;
        }
        vec[j+1] = val;
        cout << count << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}
