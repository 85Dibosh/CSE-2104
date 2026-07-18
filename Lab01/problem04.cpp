#include <iostream>
using namespace std;

int encryptID(int id);
int main(){
    int id;
    cin >> id;

    int result = encryptID(id);

    cout << result << endl;
    return 0;
}

int encryptID(int id){
    int newID=0,valueMultiplier=1;
    while(id > 0){
        int digit = id % 10;
        int newDigit = digit + 5;

        if(newDigit > 9) newDigit = newDigit % 10;

        newID = newID + (newDigit*valueMultiplier);
        valueMultiplier *= 10;
        id /= 10;

    }
    return newID;
}
