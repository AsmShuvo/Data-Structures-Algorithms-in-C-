#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v) // pass by value
{
    v[0]=0;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    
    cout << endl;
}
void change2(vector<int> &v) // pass by reff
{
    v[0]=0;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    print(v);

    for (auto it : v)
        cout << it << " ";
    cout << endl;

    change2(v);

    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
