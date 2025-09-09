#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> &v, int i)
{
    if (i == v.size() - 1)
        return v[i];
    return v[i] + sum(v, i + 1);
}

// int sum(vector<int> &v, int i)
// {
//     // from 0 to n
//     if (i == 0)
//         return v[i];
//     return v[i] + sum(v, i - 1);
// }

int getMax(vector<int> &v, int i)
{
    if (i == v.size() - 1)
        return v[i];
    int nextMax = getMax(v, i + 1);
    return max(nextMax, v[i]);
}

int main()
{
    vector<int> v = {3, 2, 4};
    // STL:
    // cout << *max_element(v.begin(), v.end()) << endl;
    // cout << *min_element(v.begin(), v.end()) << endl;
    // cout << accumulate(v.begin(), v.end(), 0) << endl;

    cout << sum(v, 0) << endl;
    cout << getMax(v, 0) << endl;
}

// multiplication of the elements of a vector
// find minimum