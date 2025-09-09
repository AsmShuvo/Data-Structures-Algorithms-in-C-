// pallindrome: abccba pqp
#include <bits/stdc++.h>
using namespace std;

bool check(string &s)
{
    int i = 0, j = s.size() - 1; // abba
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

bool checkRec(int i, int j, string &s)
{
    if (i >= j)
        return true;
    if (s[i] != s[j])
        return false;
    checkRec(i + 1, j - 1, s);
}

int main()
{
    string s = "abbu";
    if (checkRec(0, s.size()-1, s))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}