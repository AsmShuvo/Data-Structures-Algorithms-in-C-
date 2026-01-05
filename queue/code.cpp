#include <bits/stdc++.h>
using namespace std;
// push
// pop
// front
// back
// size
// print

const int sz = 100;
int q[sz];
int f = -1, b = -1;

void push(int val)
{
    if (f == -1) // checking empty
        f++;
    b++;
    q[b] = val;
}

void pop()
{
    if (f == -1)
    {
        // warning
        cout << "Queue is empty, nothing to pop";
        return;
    }
    f++;
}

int front()
{
    return q[f];
}

int back()
{
    return q[b];
}

int Size()
{
    return b - f + 1;
}

void print()
{
    while (f <= b)
    {
        cout << q[f] << " ";
        f++;
    }
    cout << endl;
    // reset
    f = -1;
    b = -1;
}

int main()
{
    push(2);
    push(3);
    push(4);

    cout << front() << " " << back() << endl;
    pop();
    cout << front() << " " << back() << endl;
    cout << Size() << endl;
    push(3);
    push(4);
    push(8);
    push(4);
    print();
}

// stack n 1 2 3 4 ...n top(n)
// quue n 1 2 3 4 ...n front(1)