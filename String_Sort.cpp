#include <bits/stdc++.h>
using namespace std;

string sort(string s)
{
    int n = s.size();
    vector<int> count(26, 0);
    int index;

    for (int i = 0; i < n; i++)
    {
        index = s[i] - 'a';
        count[index]++;
    }

    string sortedS;
    for (int i = 0; i < 26; i++)
    {
        char c = 'a' + i;
        int m = count[i];
        while (m)
        {
            sortedS.push_back(c);
            m--;
        }
    }

    return sortedS;
}

int main()
{
    string S = "edcab";

    string sortedS = sort(S);
    cout << sortedS;
    return 0;
}