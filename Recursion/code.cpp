#include <bits/stdc++.h>
using namespace std;

void f(int n)
{
    if (n == 0)
        return;
    cout << "start of process: " << n << endl;
    f(n - 1);
    cout << "end of process: " << n << endl;
}

int main()
{
    f(5);
}