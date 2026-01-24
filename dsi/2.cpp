// Q.Given an array of n integers. You need to take all zeroes in an array to the end without changing the relative
// order of the remaining element. eg: [2,0,0,3,1,0,5] => [2,3,1,5,0,0,0]

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {2, 0, 0, 3, 1, 0, 5};
    int p = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i])
        {
            v[p++] = v[i];
        }
    }
    while (p < v.size())
        v[p++] = 0;
    for (auto it : v)
        cout << it << " ";
}