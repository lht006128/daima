#include <bits/stdc++.h>

#define ll long long
using namespace std;
int a[30];
int b[30];
int n, m;

int ans = 0;

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int i = 0; i < (1 << n); i++)
  {
    if (__popcount(i) == n - m)
    {
      std::bitset<2010> bit;
      bit[0] = 1;
      for (int j = 0; j < n; j++)
      {
        if ((1 << j) & i)
        {
          bit |= bit << a[j];
        }
      }
      ans = max<ll>(ans, bit.count());
    }
  }
  cout << ans - 1;
}