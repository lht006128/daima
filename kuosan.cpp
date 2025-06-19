#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
  int ans = 0;
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = -4040; i <= 4040; i++)
  {
    for (int j = -4040; j <= 4040; j++)
    {
      if (abs(i - 0) + abs(j - 0) <= 2020 || abs(i - 2020) + abs(j - 11) <= 2020 || abs(i - 11) + abs(j - 14) <= 2020 || abs(i - 2000) + abs(j - 2000) <= 2020)
      {
        ans++;
      }
    }
  }
  cout << ans;
}