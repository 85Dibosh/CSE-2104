#include <iostream>
using namespace std;

int main(){
    int number,odds=0;
    cin >> number;

    if(number == 0) odds = 0;
    while(number > 0){
        int digit = number % 10;
        if(digit % 2 != 0) odds++;
        number = number / 10;
    }

    cout << odds << endl;
    return 0;
}
