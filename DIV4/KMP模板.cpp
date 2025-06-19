#include <bits/stdc++.h>
using namespace std;
int nxt2[1000005];
string s1;
string s2;
int ans;

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  nxt2[0] = 0;
  cin >> s1;
  cin >> s2;
  int j = 0;
  for (int i = 1; i < s2.size(); i++)
  {
    while (j && s2[i] != s2[j])
    {
      j = nxt2[j - 1];
    }
    if (s2[i] == s2[j])
      j++;
    nxt2[i] = j;
  }
  j = 0;

  for (int i = 0; i < s1.size(); i++)
  {
    while (j && s1[i] != s2[j])
    {
      j = nxt2[j - 1];
    }
    if (s2[j] == s1[i])
      j++;
    if (j == s2.size())
    {
      ans++;
      cout << i + 2 - s2.size() << endl;
      j = nxt2[j - 1];
    }
  }

  for (int i = 0; i < s2.size(); i++)
  {
    cout << nxt2[i] << " ";
  }

  return 0;
}