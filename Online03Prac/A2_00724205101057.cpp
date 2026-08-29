#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int roll;
    int number;
};

void Merge(vector<Student>& stu, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    vector<Student> temp(stu.size());
    while(i <= mid && j <= high)
    {
        //if(stu[i].number != stu[j].number)
        //{
            if(stu[i].number < stu[j].number)
            {
                temp[k].number = stu[i].number;
                temp[k].roll = stu[i].roll;
                i++;
            }
       // }
        else if(stu[i].number == stu[j].number)
        {
            if(stu[i].roll < stu[j].roll)
            {
                temp[k].number = stu[i].number;
                temp[k].roll = stu[i].roll;
                i++;
            }else{
                temp[k].number = stu[j].number;
                temp[k].roll = stu[j].roll;
                j++;
            }
        }
        else
        {
            temp[k].number = stu[j].number;
            temp[k].roll = stu[j].roll;
            j++;
        }
        k++;
    }

    while( i <= mid)
    {
        temp[k].number = stu[i].number;
        temp[k].roll = stu[i].roll;
        i++;
        k++;
    }
    while( j <= high)
    {
        temp[k].number = stu[j].number;
        temp[k].roll = stu[j].roll;
        j++;
        k++;
    }

    for(int x = low; x < high; x++){
        stu[x].roll = temp[x].roll;
        stu[x].number = temp[x].number;
    }
}

void MergeSort(vector<Student>& stu, int low, int high){
    if( low < high){
        int mid = low + (high - low) / 2;
        MergeSort(stu,low,mid);
        MergeSort(stu,mid+1,high);
        Merge(stu,low,mid,high);
    }

}

int main()
{
    int n;
    cin >> n;
    vector<Student> stu(n);
    for(int i = 0; i < n; i++)
    {
        cin >> stu[i].roll;
        cin >> stu[i].number;
    }

    MergeSort(stu,0,n-1);
    for(int i = 0; i < n; i++){
        cout << stu[i].roll << " " <<  stu[i].number;
        cout<< endl;
    }
    return 0;
}
