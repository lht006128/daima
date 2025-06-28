#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 998244353;
int n;
const int MAXN = 1e7 + 10;
int ny[MAXN];
bool isprime[MAXN];
int prime[MAXN];
int cnt = 0;
int t = 1;

int ans = 0;
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;

  ny[1] = 1;
  memset(isprime, true, sizeof(isprime));
  auto ksm = [&](int x, int p)
  {
    int res = 1;
    while (p)
    {
      if (p & 1)
        res = res * x % mod;
      x = x * x % mod;
      p >>= 1;
    }
    return res % mod;
  };

  isprime[1] = false;
  for (int i = 2; i <= n; i++)
  {
    ny[i] = (mod - mod / i) * ny[mod % i] % mod;
    if (isprime[i])
    {
      prime[++cnt] = i;
      t = (t * ksm(i, (int)(log(n) / log(i)))) % mod;
    }
    for (int j = 1; j <= cnt && i * prime[j] <= n; ++j)
    {
      isprime[i * prime[j]] = false;
      if (i % prime[j] == 0)
        break;
    }
  }

  for (int i = 1; i <= n; i++)
  {
    ans = (ans + (t * ny[i] % mod) * (n - i * 2 + 1) % mod + mod) % mod;
  }
  cout << ans;
}