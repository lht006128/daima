#include <bits/stdc++.h>
using namespace std;
// #define int long long
map<string, int> mp;
int h[130];
string s[300000];
int cnt[28][200010];
int minl = 1e17;
int suml = 0;
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> s[i];

    if (i == 1)
    {
      minl = s[i].size();
    }
    else
    {
      minl = gcd(minl, s[i].size());
    }
    suml += s[i].size();
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j - minl + 1 < s[i].size(); j += minl)
    {
      string ts;
      ts = s[i].substr(j, minl);
      for (int k = 1; k <= minl; k++)
      {
        cnt[s[i][k] - 'a'][k]++;
      }
    }
  }

  return 0;
}