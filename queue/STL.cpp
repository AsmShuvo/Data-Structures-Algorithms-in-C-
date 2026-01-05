#include <bits/stdc++.h>
using namespace std;

queue<int> q;
void print()
{
    while (q.size() > 0)
    {
        cout << q.front() << " ";
        q.pop();
    }
}

int main()
{
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.pop();

    cout << q.front() << endl; // 3
    cout << q.back() << endl;  // 5
    cout << q.size() << endl;  // 3
}