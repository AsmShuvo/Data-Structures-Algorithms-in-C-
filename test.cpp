#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string> &words)
{
    unordered_map<string, bool> mp;
    for (const string &word : words)
        mp[word] = true;
    int mxLen = 0;
    for (string w : words)
    {
        mxLen = max(mxLen, w.size());
    }
    int n = s.length();
    vector<int> dp(n + 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= max(0, i - mxLen); j--)
        {
            if (dp[j] && mp.find(s.substr(j, i - j)) != mp.end())
            {
                dp[i] = true;
                break; 
            }
        }
    }
    // abcdef
}

int main()
{
    string s = "catsanddogs";
    vector<string> words = {"dogs", "cats", "and"};
}