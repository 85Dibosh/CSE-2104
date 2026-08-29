#include <bits/stdc++.h>
using namespace std;

int calc(int a, int b, char op)
{
    if(op == '/') return a/b;
    if(op == '*') return a*b;
    if(op == '+') return a+b;
    if(op == '-') return a-b;
    return 0;
}

int prec(char op)
{
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string post = "";

    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        if( c == ' ') continue;
        if( c >= '0' && c<= '9')
        {
            while(i < s.size() && s[i] >= '0' && s[i]<= '9')
            {
                post += s[i];
                i++;
            }
            post += " ";
            i--;
        }
        else if(c == '(')
        {
            st.push('(');
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                post += st.top();
                post += " ";
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && prec(st.top()) >= prec(c)) {
                post += st.top();
                post += " ";
                st.pop();
            }
            st.push(c);
        }

    }
    while (!st.empty()) {
        post += st.top();
        post += " ";
        st.pop();
    }

    return post;
}

int evaluatePostfix(string post) {
    stack<int> st;

    for (int i = 0; i < post.length(); i++) {
        char c = post[i];

        if (c == ' ') continue;
        if (c >= '0' && c <= '9') {
            int num = 0;
            while (i < post.length() && post[i] >= '0' && post[i] <= '9') {
                num = num * 10 + (post[i] - '0');
                i++;
            }
            st.push(num);
            i--;
        }
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(calc(a, b, c));
        }
    }

    return st.top();
}

int main()
{
    string infix = "(12 + 34) * 56 - 78 / 9";

    string postfix = infixToPostfix(infix);
    int result = evaluatePostfix(postfix);

    cout << "Infix:   " << infix << endl;
    cout << "Postfix: " << postfix << endl;
    cout << "Result:  " << result << endl;

    return 0;
}
