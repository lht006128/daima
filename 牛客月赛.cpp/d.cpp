#include <bits/stdc++.h>
using namespace std;
// #define int long long
map<string, int> mp;

string s[300000];
int minl = 1e7;
int ans = 1e8;
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> s[i];
    int tp;
    if (i == 1)
    {
      tp = s[i].size();
    }
    else
    {
      tp = gcd(tp, s[i].size());
    }

    minl = min(tp, minl);
  }

  return 0;
}