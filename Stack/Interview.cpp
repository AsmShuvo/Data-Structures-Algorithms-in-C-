// valid paranthesis
//  (1+[2-(5^2)/2)*4)] invalid
//  {[]()} valid

//
// 1- () valid (} invalid
// 2- ({([ -- ])}) LIFO
// 3- (()))

#include <bits/stdc++.h>
using namespace std;

void call()
{
    cout << "tesing..." << endl;
}

bool isValid(string s)
{
    call();
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        // if opening , push
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        { // closing
            if (st.size() == 0)
            {
                return false;
            }
            // check the same opening
            if (s[i] == ')' && st.top() != '(')
                return false;
            if (s[i] == '}' && st.top() != '{')
                return false;
            if (s[i] == ']' && st.top() != '[')
                return false;
            st.pop();
        }
    }
    if (st.size() == 0)
        return true;
    else
        return false;
}

int main()
{
    string s;
    getline(cin, s);
    // string newS;
    // for (char c : s)
    // {
    //     if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    //         newS += tolower(c);
    // }
    // cout << newS;
    cout << isValid(s) << endl;
}
