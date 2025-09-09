#include <bits/stdc++.h>
using namespace std;

void reverseRec(int i, int j, string &s)
{
    // cout << s << endl;
    if (i >= j)
        return;
    swap(s[i], s[j]);
    reverseRec(i + 1, j - 1, s);

    
}

int main()
{
    string s = "Mahdy Shuvo"; // o/p: ovuhs ydham

    // STL:
    // reverse(s.begin(), s.end());
    int i = 0, j = s.size() - 1;
    // while (i < j)
    // {
    //     swap(s[i], s[j]);
    //     i++;
    //     j--;
    // }

    reverseRec(i, j, s);

    cout <<"Output: "<< s << endl;
}

// abcde -> ebcda -> edcba