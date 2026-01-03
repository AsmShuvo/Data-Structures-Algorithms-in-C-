// Array
// LinkedList
// BuildInLib STL

// Operations: Push, Pop, Top
// Implementation using Array

#include <bits/stdc++.h>
using namespace std;

// global var
int t = -1;
const int sz = 5;
int Stack[sz];

void push(int val)
{
    if (t == sz - 1)
    {
        // WARNING
        cout << "Stack overflow" << endl;
        return;
    }
    t++;
    Stack[t] = val;
}

void pop()
{
    if (t == -1)
    {
        cout << "Stack is empty so you can't pop";
        return;
    }
    t--;
}

void top()
{
    if (t == -1)
    {
        cout << "Stack is empty so you can't get top";
        return;
    }
    cout << Stack[t];
}

void print()
{
    while(t!=-1){
        top();
        pop();
    }
}

int Size(){
    return t+1;
}

int main()
{
    push(3);
    push(4);
    push(1);
    push(3);
    // print();
    cout<<endl;
    cout<<Size();
}