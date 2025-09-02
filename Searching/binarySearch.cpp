#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // sort
    sort(v.begin(), v.end());
    cout << "Vector after sorting: " << endl;
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
    int target;
    cin >> target;

    // binary search stl
    bool exists = binary_search(v.begin(), v.end(), target);
    if (exists == true)
        cout << "the element found" << endl;
    else
    {
        cout << "Not found" << endl;
        return 0; // finish
    }

    // lower bound :
    auto lb = lower_bound(v.begin(), v.end(), target);
    int index = lb - v.begin();
    cout << "found at: " << index << endl;

    // upper bound
    auto ub = upper_bound(v.begin(), v.end(), target);
    int id = ub - v.begin();
    cout << "found at: " << id << endl;

    // count the occurance/ freq of target
    int cnt=0;
    for(int i=0; i<n; i++){
        if(v[i]==target){
            cnt++;
        }
    }
    cout<<"Novice approach count: "<<cnt<<endl;

    // smart approach
    cout<<"smart binary Search approach count: "<<ub-lb<<endl;
}

//  Binary Search -> exists or not: bool
// lower bound -> if exist : then return  index , else: return next greater element
// upper bound -> return next greater element

// iterator: pointer -> which points over a memory address