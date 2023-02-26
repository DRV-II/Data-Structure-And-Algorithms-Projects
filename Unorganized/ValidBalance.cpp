/*
Programa que valida el balance de parentesis
Alumno: David Román Velasco A01639645
Hecho en colaboración de:
Paulina Lizet Gutiérrez Amezcua A01639948,
Juan Pablo García Malta A01639025
echa de creación: 9 de septiembre del 2021
*/

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
