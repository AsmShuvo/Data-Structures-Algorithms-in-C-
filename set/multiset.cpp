#include <bits/stdc++.h>
using namespace std;

int main()
{
    multiset<char> ms;
    ms.insert('s');
    ms.insert('a');
    ms.insert('s');
    ms.insert('b');

    multiset<string> ms2;

    ms2.insert("shuvo");
    ms2.insert("Shuvo");
    ms2.insert("Mahdi");
    ms2.insert("mahdi");
    ms2.insert("?ahdi");
    ms2.insert("mahbi");
    ms2.insert("Ronaldo");
    ms2.insert("Ronaldo");

    multiset<string> ms3;
    ms3.insert("ac");
    ms3.insert("abb");
    ms3.insert("abba");

    for (char c : ms)
        cout << c << " ";
    cout << endl;
    for (string c : ms2)
        cout << c << " ";
    cout << endl;
    for (string c : ms3)
        cout << c << " ";
    cout << endl;

    auto ptr = ms2.find("ronaldo");
    if(ptr==ms2.end()) cout<<"not found"<<endl;
    else {
        cout<<"found"<<endl;
        cout<<distance(ms2.begin(),ptr)<<endl; // position of the first occurrence
        ms2.erase(ptr); // only one occurrence will be deleted
        ms2.erase("shuvo"); // all occurrences will be deleted
    }
}

// insert delete find : O(log n)

// a b c d _END