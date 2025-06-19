#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[100010];
void slove()
{
  int n, k;
  cin >> n >> k;
  int ans = 0;
  ans++;
  if (n % 2 == 0)
  {
    ans += k;
  }

  cout << ans << endl;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  dp[0] = 1;
  dp[1] = 2;
  dp[2] = 2;
  for (int i = 3; i <= 100000; i++)
  {
    dp[i] = dp[i / 2] + 1;
  }

  cout << dp[6];

  int t;
  cin >> t;
  while (t--)
  {
    slove();
  }
}