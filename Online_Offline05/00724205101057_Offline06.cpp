#include <bits/stdc++.h>
using namespace std;

int prec(char op){
    if(op == ' * ' || op == ' / ') return 2;
    if(op == ' + ' || op == ' - ') return 1;
    return 0;
}

string infixToPostfix(string infix){
    stack<char> st;
    string postfix = "";

    for(int i = 0; i < infix.size(); i++){
        char c = infix[i];

        if(c == ' ') continue;

        if(isdigit(c)){
            while ( i < infix.size() && isdigit(infix[i])){
                postfix += infix[i];
                i++;
            }
        }
    }
}
int main(){

}
