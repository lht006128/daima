#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[3000010];
int dp[3000010];

struct Node
{
  int w;
  int next;
};
Node arr[3090010];

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    if (i == 1)
    {
      dp[i] = 1;
    }
    else
    {

      if (a[i] > a[i - 1])
      {

        dp[i] = dp[i - 1] + 1;
      }
      else
      {
        dp[i] = 1;
      }
    }
  }

  for (int i = 1; i <= n - 1; i++)
  {
    if (i == 1)
    {
      arr[1].w = 3;
    }
    else
    {
      if (a[i] > a[i - 1] && a[i] > a[i + 1])
      {
        arr[i].w = 1;
      }
      else if (a[i] < a[i - 1] && a[i] < a[i + 1])
      {
        arr[i].w = 2;
      }
      else
      {
        arr[i].w = 3;
      }
    }
  }

  int now = 3;
  int nep = n;
  for (int i = n; i >= 1; i--)
  {
    arr[i].next = nep;

    if (arr[i].w != 3)
    {
      now = arr[i].w;
      nep = i;
    }
  }

  int ans = 0;

  for (int i = 1; i <= n; i++)
  {

    if (arr[i].w != 3)
    {
      if (arr[i].w == 1)
      {
        if (arr[i].next != n && arr[arr[i].next].w == 2)
        {
          // cout << i << " " << endl;
          // cout << dp[i] - 1 << endl;
          ans += (dp[i] - 1) * (arr[arr[i].next].next - arr[i].next);
        }
      }
      else if (arr[i].w == 2 && arr[i].next != n && arr[i].w == 1)
      {
        ans += (arr[arr[i].next].next - arr[i].next);
      }
    }
  }

  cout << ans;
}
