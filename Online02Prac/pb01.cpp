#include <bits/stdc++.h>
using namespace std;

struct Employee{
    string name;
    string dept;
    int salary;
};

void selectionSort(vector<Employee>& emp){
    int n = emp.size();
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(emp[min].salary != emp[j].salary)
                if(emp[min].salary < emp[j].salary){
                    min = j;
                }
            else if(emp[min].dept != emp[j].dept)
                if(emp[min].dept > emp[j].dept){
                    min = j;
                }
            else if(emp[min].name > emp[j].name)
                min = j;

        }
        swap(emp[i],emp[min]);
    }
}

int main(){
    int n;
    cin >> n;
    vector<Employee> emp(n);
    for(int i = 0; i < n; ++i){
        getline(cin >> ws, emp[i].name,',');
        getline(cin >> ws, emp[i].dept,',');
        cin >> emp[i].salary;
    }

    selectionSort(emp);

    for(const auto& e: emp){
        cout << e.name << " " <<  e.dept << " " << e.salary << "\n";
    }
    return 0;
}
