#include <bits/stdc++.h>
// #include<vector>
using namespace std;

int main()
{
    vector<int> a, v = {4, 2, 4, 1}; // initialize
    cout << a.size() << " " << v.size() << endl;
    vector<int> v1(5); // size defined: all initialized with 0
    for (int i : v1)
        cout << i << " ";
    cout << endl;
    v1.push_back(5);
    v1.push_back(15);
    for (int i : v1)
        cout << i << " ";
    cout << endl;

    int n;
    cin >> n;
    vector<int> arr(n);
    // 0 0 0 0 0
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
}

// if you want to push_back, dont initialize the vector with size
// or if u have initialized with size, u have to take input like an array