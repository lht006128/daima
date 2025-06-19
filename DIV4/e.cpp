#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[30010];

void slove()
{
  int n;
  cin >> n;
  int ans = -1;
  int idx = -1;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++)
  {
    int sum = 0;

    for (int j = 1; j <= n; j++)
    {
      sum += (a[i] ^ a[j]);
    }
    if (sum > ans)
    {
      ans = sum;
      idx = i;
    }
  }
  cout << ans << " " << a[idx] << endl;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;

  while (t--)
  {
    slove();
  }
}