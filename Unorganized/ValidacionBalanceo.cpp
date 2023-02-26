/*
#include <bits/stdc++.h>
using namespace std;

// function to check if brackets are balanced
bool areBracketsBalanced(string expr)
{
    stack<char> s;
    char x;

    // Traversing the Expression
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '['|| expr[i] == '{')
        {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }

        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (s.empty())
            return false;

        switch (expr[i]) {
        case ')':

            // Store the top element in a
            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;

        case '}':

            // Store the top element in b
            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;

        case ']':

            // Store the top element in c
            x = s.top();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }

    // Check Empty Stack
    return (s.empty());
}

// Driver code
int main()
{
    string expr = "{()}[]";

    // Function call
    if (areBracketsBalanced(expr))
        cout << "Balanced"<<endl;
    else
        cout << "Not Balanced"<<endl;
    return 0;
}*/
#include <iostream>
#include <stack>
using namespace std;


bool isValid(string s)
{
    stack<char> ss;
    int size = 0;
    for (auto x : s)
    {
        if (x == '(' || x == '{' || x == '[')
            ss.push(x);
        else if (x == ')' && !ss.empty() && ss.top() == '(')
            ss.pop(), size += 2;
        else if (x == ']' && !ss.empty() && ss.top() == '[')
            ss.pop(), size += 2;
        else if (x == '}' && !ss.empty() && ss.top() == '{')
            ss.pop(), size += 2;
    }
    if (size == s.length())
        return true;
    else
        return false;
}


int main() {
  string pare="(]";
  cout<<pare<<endl;
  bool val=isValid(pare);
  cout<<val<<endl;
  return 0;
}
