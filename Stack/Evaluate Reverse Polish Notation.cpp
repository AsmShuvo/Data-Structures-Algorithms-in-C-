#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string> &v)
{
    stack<int> st; // stl
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/")
        {
            int t1, t2;
            // 4 5 +
            t1 = st.top(); // 5
            st.pop();
            t2 = st.top(); // 4
            st.pop();
            int val;
            if (v[i] == "+")
                val = t2 + t1;
            if (v[i] == "-")
                val = t2 - t1;
            if (v[i] == "*")
                val = t2 * t1;
            if (v[i] == "/")
                val = t2 / t1;
            st.push(val);
        }
        else
        {
            // "100" --> 100
            int val = stoi(v[i]);
            st.push(val);
        }
    }
    return st.top();
}

int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout<<evalRPN(v)<<endl;
}