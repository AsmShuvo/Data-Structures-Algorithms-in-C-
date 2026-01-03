#include <bits/stdc++.h>
#include <stack>
using namespace std;

stack<int> st;
void print()
{
    // O(n)
    while (st.size() > 0)
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    // push
    st.push(5);
    st.push(51);
    st.push(192);
    st.push(69);

    print();
    st.push(69);
    cout << st.empty() << endl;
    // cout << (st.size()>0) << endl;
}

/*
Operation	                Time Complexity
Insert an element (push)	O(1)
Delete an element (pop)	    O(1)
Access top element (peek)	O(1)
Traverse the stack	        O(n)
*/