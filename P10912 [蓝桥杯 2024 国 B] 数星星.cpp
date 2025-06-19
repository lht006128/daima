#include <bits/stdc++.h>
#define int long long
using namespace std;

int mod = 1e9 + 7;
int jcs[100005];
int inv[100005];

int ksm(int x, int p)
{
  int res = 1;
  while (p)
  {
    if (p & 1)
      res = (res * x) % mod;
    x = (x * x) % mod;
    p >>= 1;
  }
  return res % mod;
}

void init(int n)
{
  inv[0] = 1;
  // inv[1] = 1;
  // jcs[0] = jcs[1] = 1;

  int jc = 1;
  for (int i = 1; i <= n; i++)
  {
    jc = (jc * i) % mod;
    jcs[i] = jc;
    inv[i] = ksm(jc, mod - 2) % mod;
    // jc = jc * i % mod;
    // // jcs[i] = i * jcs[i - 1] % mod;
    // jcs[i] = jc;
    // inv[i] = ksm(jc, mod - 2) % mod;
  }
}
int dushu[510000];
int ans;

int calc(int n, int m)
{
  int tp;
  tp = ((jcs[n] * inv[m]) % mod * inv[n - m]) % mod;
  return tp;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  init(n + 5);
  for (int i = 1; i <= n - 1; i++)
  {
    int x, y;
    cin >> x >> y;
    dushu[x]++;
    dushu[y]++;
  }
  int l, r;
  cin >> l >> r;

  for (int i = 1; i <= n; i++)
  {
    if (dushu[i] >= (l - 1))
    {
      for (int j = l - 1; j <= min(dushu[i], r - 1); j++)
      {
        ans = (ans + calc(dushu[i], j)) % mod;
        // cout << calc(dushu[i], j) << " " << dushu[i] << " " << j << endl;
      }
    }
  }
  if (l <= 2 && r >= 2)
    ans = (ans - n + 1 + mod) % mod;

  cout << ans % mod;
  return 0;
}