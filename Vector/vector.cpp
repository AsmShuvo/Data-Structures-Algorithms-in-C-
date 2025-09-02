#include <bits/stdc++.h>
// #include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v; // empty vector
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x); //push into the vector
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    // for each loop
    for(int i: v){
        cout<<i<<" ";
    }
    // iterates over element
}

//  push
// size
// begin() --> points to starting element
// end()--> points to the address after the last element