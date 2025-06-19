#include <bits/stdc++.h>
#define int long long
using namespace std;

int arr[100];

void slove()
{
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }

  sort(arr + 1, arr + 1 + n);

  int ans = 1e9;

  // 开头从后往前找
  for (int i = n; i >= 1; i--)
  {
    if ((arr[1] + arr[i]) % 2 == 0)
    {
      ans = min(ans, n - i);
    }
  }
  // 从后往前找
  for (int i = 1; i <= n; i++)
  {
    if ((arr[n] + arr[i]) % 2 == 0)
    {
      ans = min(ans, i - 1);
    }
  }

  cout << ans << endl;
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